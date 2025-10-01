#include <iostream>
#include "OpenGL/openGL.h"

#include "OBJ/OBJ.hpp"
#include "OBJ/OBJ_Main.hpp"
#include "OBJ/OBJ_3D_BufferArray.hpp"
#include "OBJ/OBJ_3D_Shader.hpp"

#include "Graphics/Uniform/Uniforms.hpp"
#include "Graphics/Multiform/Data/2D/UniSizeRatio2D.hpp"
#include "Graphics/Multiform/Data/3D/UniTrans3D.hpp"
#include "Graphics/Multiform/Data/UniDepth.hpp"

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

MultiSizeRatio2D * Multi_ViewPortSizeRatio;
MultiTrans3D * Multi_View;
MultiDepth * Multi_Depth;

Trans3D view_trans;



void InitShaders()
{
	OBJ_Shader = new OBJ_3D_Shader(ShaderDir);
	win -> DefaultColor = Color(0.25f, 0.0f, 0.0f);

	Depth Depth;
	Depth.Factors = DepthFactors(0.1f, 10.0f);
	Depth.Range = Range(0.8f, 1.0f);
	Depth.Color = win -> DefaultColor;

	Multi_ViewPortSizeRatio = new MultiSizeRatio2D("ViewPortSizeRatio");
	Multi_View = new MultiTrans3D("View");
	Multi_Depth = new MultiDepth("Depth");

	BaseShader * shaders [] = {
		OBJ_Shader,
	};
	int shader_count = 1;

	Multi_ViewPortSizeRatio -> FindUniforms(shaders, shader_count);
	Multi_View -> FindUniforms(shaders, shader_count);
	Multi_Depth -> FindUniforms(shaders, shader_count);

	Multi_Depth -> ChangeData(Depth);
}
void FreeShaders()
{
	delete OBJ_Shader;

	delete Multi_ViewPortSizeRatio;
	delete Multi_View;
	delete Multi_Depth;
}



void Init()
{
	std::cout << "Init 0\n";

	InitShaders();

	Tex0 = new TextureArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
		//ImageDir.File("GrayDeant.png"),
	});
	OBJ_BufferArray = new OBJ_3D_BufferArray();

	{
		int count;
		OBJ_MainData * data;
		data = obj -> ToMainData(count);
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
