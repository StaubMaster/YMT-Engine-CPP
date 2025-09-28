#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract.hpp"

#include "Graphics/PH/PH_3D/PolyHedra_3D_Instances.hpp"
#include "Graphics/PH/PH_3D/PolyHedra_3D_Shader.hpp"
#include "Graphics/Uniform/Uniforms.hpp"

#include "TextureArray.hpp"
#include "PolyHedra.hpp"
#include "Window.hpp"

#include "FileManager/DirectoryContext.hpp"
#include "FileManager/FileContext.hpp"
#include "FileManager/Format/Image.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



Window * win;

YMT::PolyHedra * Poly0;
TextureArray * Tex0;

PolyHedra_3D_Instances * PH_Instances;
EntryContainerDynamic<PolyHedra_3D_InstData>::Entry ** Entrys;
PolyHedra_3D_Shader * PH_Shader;

MultiSizeRatio2D * Multi_ViewPortSizeRatio;
MultiTrans3D * Multi_View;
MultiDepth * Multi_Depth;

Transformation3D view_trans;



void InitShaders()
{
	PH_Shader = new PolyHedra_3D_Shader(ShaderDir);
	win -> DefaultColor = Color(0.25f, 0.0f, 0.0f);

	Depth Depth;
	Depth.Factors = DepthFactors(0.1f, 100.0f);
	Depth.Range = Range(0.8f, 1.0f);
	Depth.Color = win -> DefaultColor;

	Multi_ViewPortSizeRatio = new MultiSizeRatio2D("ViewPortSizeRatio");
	Multi_View = new MultiTrans3D("View");
	Multi_Depth = new MultiDepth("Depth");

	BaseShader * shaders [] = {
		PH_Shader,
	};
	int shader_count = 1;

	Multi_ViewPortSizeRatio -> FindUniforms(shaders, shader_count);
	Multi_View -> FindUniforms(shaders, shader_count);
	Multi_Depth -> FindUniforms(shaders, shader_count);

	Multi_Depth -> ChangeData(Depth);
}
void FreeShaders()
{
	delete PH_Shader;

	delete Multi_ViewPortSizeRatio;
	delete Multi_View;
	delete Multi_Depth;
}

void AddInstances()
{
	int j_len = 16;
	int i_len = 16;
	Entrys = new EntryContainerDynamic<PolyHedra_3D_InstData>::Entry*[j_len];
	for (int j = 0; j < j_len; j++)
	{
		Entrys[j] = PH_Instances -> Alloc(i_len);
		Point3D center(
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF
		);
		Angle3D rot(
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF,
			(std::rand() & 0x1F) - 0xF
		);
		for (int i = 0; i < i_len; i++)
		{
			(*Entrys[j])[i].Trans.Pos = center + Point3D(
				(std::rand() & 0x1F) - 0xF,
				(std::rand() & 0x1F) - 0xF,
				(std::rand() & 0x1F) - 0xF
			);
			(*Entrys[j])[i].Trans.Rot = rot;
		}
	}

	{
		int MemSize = (PH_Instances -> Instances.Length) * sizeof(PolyHedra_3D_InstData);
		std::cout << "Count: " << (PH_Instances -> Instances.Length) << "\n";
		std::cout << (MemSize / (1)) << " Bytes\n";
		std::cout << (MemSize / (1 * 1000)) << "k Bytes\n";
		std::cout << (MemSize / (1 * 1000 * 1000)) << "M Bytes\n";
	}
}



void Init()
{
	std::cout << "Init 0\n";

	InitShaders();

	//Poly0 = YMT::PolyHedra::FullTexture();
	Poly0 = YMT::PolyHedra::Cube();
	//Poly0 = YMT::PolyHedra::ConeC(12, 0.5f);
	
	Poly0 -> UseCornerNormals = false;
	Tex0 = new TextureArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
		//ImageDir.File("GrayDeant.png"),
	});
	PH_Instances = new PolyHedra_3D_Instances(Poly0);
	AddInstances();

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	delete PH_Instances;
	delete [] Entrys;
	delete Tex0;
	delete Poly0;

	FreeShaders();

	std::cout << "Free 1\n";
}

void Frame(double timeDelta)
{
	view_trans.TransformFlatX(win -> MoveFromKeys(2.0f * timeDelta), win -> SpinFromCursor(0.2f * timeDelta));
	Multi_View -> ChangeData(view_trans);

	PH_Shader -> Use();
	Tex0 -> Bind();
	PH_Instances -> Update();
	PH_Instances -> Draw();
}

void Resize(int w, int h)
{
	Multi_ViewPortSizeRatio -> ChangeData(SizeRatio2D(w, h));
}



int main()
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

	view_trans = Transformation3D(
		Point3D(0, 0, 0),
		Angle3D(0, 0, 0)
	);



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}
