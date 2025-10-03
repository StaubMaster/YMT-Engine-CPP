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
#include "DataStruct/AxisBox3D.hpp"
#include "DataO.hpp"

#include "TextureArray.hpp"
#include "PolyHedra.hpp"
#include "Window.hpp"

#include "FileManager/DirectoryContext.hpp"
#include "FileManager/FileContext.hpp"
#include "FileManager/Format/Image.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



Window * win;

int OBJ_Count;
OBJ ** obj;
TextureArray * Tex0;

OBJ_3D_BufferArray ** OBJ_BufferArray;
OBJ_3D_Shader * OBJ_Shader;
Point3D OBJ_Center;
Trans3D OBJ_Trans;

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
	Depth.Factors = DepthFactors(0.1f, 100.0f);
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

	Tex0 = new TextureArray(ImageDir.File("Orientation.png"));

	OBJ_BufferArray = new OBJ_3D_BufferArray * [OBJ_Count];
	for (int i = 0; i < OBJ_Count; i++)
	{
		OBJ_BufferArray[i] = new OBJ_3D_BufferArray();

		int main_count;
		OBJ_MainData * main_data;
		main_data = obj[i] -> ToMainData(main_count, Tex0 -> SizeRatio);
		OBJ_BufferArray[i] -> BindMain(main_data, main_count);
		delete [] main_data;

		Simple3D_InstData inst_data []
		{
			(Simple3D_InstData)Trans3D(Point3D(), Angle3D()),
		};
		int inst_count = 1;
		OBJ_BufferArray[i] -> BindInst(inst_data, inst_count);
	}

	if (OBJ_Count != 0)
	{
		OBJ_Center = obj[0] -> ToAxisBox().Center();
	}
	OBJ_Trans = Trans3D(Point3D(0, 0, 3), Angle3D(0, 0, 0));

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	for (int i = 0; i < OBJ_Count; i++)
	{
		delete OBJ_BufferArray[i];
	}
	delete [] OBJ_BufferArray;
	delete Tex0;

	FreeShaders();

	std::cout << "Free 1\n";
}

void Update_ColorToTex()
{
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
}
void Update_ObjTrans(double timeDelta)
{
	{
		OBJ_Trans.Pos = OBJ_Trans.Pos + (OBJ_Trans.Rot.rotate_back(OBJ_Center));
		OBJ_Trans.Rot.ChangeX(OBJ_Trans.Rot.x + 0.02f);
		OBJ_Trans.Pos = OBJ_Trans.Pos - (OBJ_Trans.Rot.rotate_back(OBJ_Center));
	}
	if (!win -> IsMouseLocked())
	{
		OBJ_Trans.Pos = OBJ_Trans.Pos + win -> MoveFromKeys(2.0f * timeDelta);
	}

	if (OBJ_Count >= 1)
	{
		Simple3D_InstData inst_data []
		{
			(Simple3D_InstData)OBJ_Trans,
		};
		int inst_count = 1;
		OBJ_BufferArray[0] -> BindInst(inst_data, inst_count);
	}
}

void Frame(double timeDelta)
{
	if (win -> IsMouseLocked())
	{
		view_trans.TransformFlatX(win -> MoveFromKeys(2.0f * timeDelta), win -> SpinFromCursor(0.2f * timeDelta));
	}
	Multi_View -> ChangeData(view_trans);

	Update_ColorToTex();
	Update_ObjTrans(timeDelta);

	OBJ_Shader -> Use();
	Tex0 -> Bind();
	for (int i = 0; i < OBJ_Count; i++)
	{
		OBJ_BufferArray[i] -> Draw();
	}
}

void Resize(int w, int h)
{
	Multi_ViewPortSizeRatio -> ChangeData(SizeRatio2D(w, h));
}



int main(int argc, char * argv [])
{
	if (argc <= 0)
	{
		std::cout << "Argc: " << argc << " <= 0\n";
		return 1;
	}

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

	OBJ_Count = argc - 1;
	obj = new OBJ * [OBJ_Count];
	for (int i = 0; i < OBJ_Count; i++)
	{
		obj[i] = OBJ::Load(FileContext(std::string(argv[i + 1])));
	}



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	for (int i = 0; i < OBJ_Count; i++)
	{
		delete obj[i];
	}
	delete [] obj;
	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}
