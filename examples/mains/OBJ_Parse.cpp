#include <iostream>
#include "OpenGL/openGL.h"

#include "OBJ/OBJ.hpp"
#include "OBJ/OBJ_Main.hpp"
#include "OBJ/OBJ_3D_BufferArray.hpp"
#include "OBJ/OBJ_3D_Shader.hpp"

#include "Graphics/Multiform/Data/SizeRatio2D.hpp"
#include "Graphics/Multiform/Data/Trans3D.hpp"
#include "Graphics/Multiform/Data/Depth.hpp"
#include "Graphics/Multiform/Data/LInter.hpp"

#include "DataStruct/LInter.hpp"

#include "TextureArray.hpp"
#include "PolyHedra.hpp"
#include "Window.hpp"

#include "FileManager/DirectoryContext.hpp"
#include "FileManager/FileContext.hpp"
#include "FileManager/Format/Image.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



Window * win;

OBJ * obj;
TextureArray * Tex0;

OBJ_3D_BufferArray * OBJ_BufferArray;
OBJ_3D_Shader * OBJ_Shader;

Multiform::SizeRatio2D * Multi_ViewPortSizeRatio;
Multiform::Trans3D * Multi_View;
Multiform::Depth * Multi_Depth;
Multiform::LInter * Multi_ColorToTex;

Trans3D view_trans;

LInter ColorToTex;
float ColorToTex_Speed = 0.01f;
bool ColorToTex_Direction = false;
bool ColorToTex_Direction_last = false;



void InitShaders()
{
	OBJ_Shader = new OBJ_3D_Shader(ShaderDir);
	win -> DefaultColor = Color(0.25f, 0.0f, 0.0f);

	Depth Depth;
	Depth.Factors = DepthFactors(0.1f, 10.0f);
	Depth.Range = Range(0.8f, 1.0f);
	Depth.Color = win -> DefaultColor;

	ColorToTex = LInter::T0();
	ColorToTex_Direction = false;

	Multi_ViewPortSizeRatio = new Multiform::SizeRatio2D("ViewPortSizeRatio");
	Multi_View = new Multiform::Trans3D("View");
	Multi_Depth = new Multiform::Depth("Depth");
	Multi_ColorToTex = new Multiform::LInter("ColorToTex");

	BaseShader * shaders [] = {
		OBJ_Shader,
	};
	int shader_count = 1;

	Multi_ViewPortSizeRatio -> FindUniforms(shaders, shader_count);
	Multi_View -> FindUniforms(shaders, shader_count);
	Multi_Depth -> FindUniforms(shaders, shader_count);
	Multi_ColorToTex -> FindUniforms(shaders, shader_count);

	Multi_Depth -> ChangeData(Depth);
	Multi_ColorToTex -> ChangeData(ColorToTex);
}
void FreeShaders()
{
	delete OBJ_Shader;

	delete Multi_ViewPortSizeRatio;
	delete Multi_View;
	delete Multi_Depth;
	delete Multi_ColorToTex;
}



void Init()
{
	std::cout << "Init 0\n";

	InitShaders();

	/*Tex0 = new TextureArray(128, 64, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
		//ImageDir.File("GrayDeant.png"),
	});*/
	Tex0 = new TextureArray(ImageDir.File("Orientation.png"));
	OBJ_BufferArray = new OBJ_3D_BufferArray();

	{
		int count;
		OBJ_MainData * data;
		data = obj -> ToMainData(count, Tex0 -> SizeRatio);
		OBJ_BufferArray -> BindMain(data, count);
		delete [] data;
	}

	{
		Simple3D_InstData data []
		{
			(Simple3D_InstData)Trans3D(Point3D(), Angle3D()),
		};
		int count = 1;
		OBJ_BufferArray -> BindInst(data, count);
	}

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	delete OBJ_BufferArray;
	delete Tex0;

	FreeShaders();

	std::cout << "Free 1\n";
}

void Frame(double timeDelta)
{
	view_trans.TransformFlatX(win -> MoveFromKeys(2.0f * timeDelta), win -> SpinFromCursor(0.2f * timeDelta));
	Multi_View -> ChangeData(view_trans);

	if (glfwGetKey(win -> win, GLFW_KEY_P))
	{
		if (ColorToTex_Direction_last == false)
		{
			ColorToTex_Direction = !ColorToTex_Direction;
			ColorToTex_Direction_last = true;
		}
	} else { ColorToTex_Direction_last = false; }

	if (!ColorToTex_Direction)
	{
		if (ColorToTex.GetT1() > ColorToTex_Speed) { ColorToTex.SetT0(ColorToTex.GetT0() + ColorToTex_Speed); }
		else { ColorToTex.SetT0(1.0); }
	}
	else
	{
		if (ColorToTex.GetT0() > ColorToTex_Speed) { ColorToTex.SetT1(ColorToTex.GetT1() + ColorToTex_Speed); }
		else { ColorToTex.SetT1(1.0); }
	}
	Multi_ColorToTex -> ChangeData(ColorToTex);

	OBJ_Shader -> Use();
	Tex0 -> Bind();
	OBJ_BufferArray -> Draw();
}

void Resize(int w, int h)
{
	Multi_ViewPortSizeRatio -> ChangeData(SizeRatio2D(w, h));
}



int main(int argc, char * argv [])
{
	if (glfwInit() == 0)
	{
		std::cout << "GLFW Init Failed\n";
		return -1;
	}

	try
	{
		win = new Window(640, 480);
		win -> InitFunc = Init;
		win -> FrameFunc = Frame;
		win -> FreeFunc = Free;
		win -> ResizeFunc = Resize;
	}
	catch (std::exception & ex)
	{
		std::cout << "exception: " << ex.what() << "\n";
	}
	catch (const char * err)
	{
		std::cerr << "String Error: "<< err << "\n";
		glfwTerminate();
		return -1;
	}
	catch (...)
	{
		std::cerr << "Unknown Error" << "\n";
		glfwTerminate();
		return -1;
	}

	view_trans = Trans3D(
		Point3D(0, 0, 0),
		Angle3D(0, 0, 0)
	);

	obj = NULL;
	if (argc == 2)
	{
		obj = OBJ::Load(FileContext(std::string(argv[1])));
	}



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";


	delete obj;
	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}
