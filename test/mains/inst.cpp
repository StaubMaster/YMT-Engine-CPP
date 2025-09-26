#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract.hpp"
#include "Uniforms.hpp"

#include "PolyHedra.hpp"
#include "PolyHedra/ShaderInst.hpp"
#include "TextureArray.hpp"

#include "Graphics/Buffer/PolyHedra_3D_Instances.hpp"

#include "Window.hpp"

#include "FileParse/PNG/PNG_Image.hpp"
#include "FileManager/FileContext.hpp"
#include "FileManager/DirectoryContext.hpp"



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");



void MoveFlatX(Transformation3D & trans, Point3D move)
{
	//trans.Pos = trans.Pos + trans.Rot.rotate_back(move);
	trans.Pos = trans.Pos + (Angle3D(trans.Rot.x, 0, 0).rotate_back(move));
}
void MoveFlatX(Transformation3D & trans, Angle3D spin)
{
	//trans.Rot = trans.Rot.rotate_fore(spin);
	trans.Rot.x = trans.Rot.x + spin.x;
	trans.Rot.y = trans.Rot.y + spin.y;
	trans.Rot.z = 0;
	trans.Rot.UpdateSinCos();
}



Window * win;

YMT::PolyHedra * Poly0;
TextureArray * Tex0;

PolyHedra_3D_Instances * PH_Instances;
EntryContainerDynamic<PolyHedra_3D_InstData>::Entry ** Entrys;

YMT::PolyHedra::ShaderInst * PolyInstShader;

UniTrans3D * Uni_Inst_View;
MultiTrans3D * Multi_View;

UniDepthFactors * Uni_Inst_DepthFactors;
MultiDepthFactors * Multi_DepthFactors;

UniSizeRatio2D * Uni_Inst_ViewPortSizeRatio;
MultiSizeRatio2D * Multi_ViewPortSizeRatio;



Transformation3D view_trans;


void InitShaders()
{
	PolyInstShader = new YMT::PolyHedra::ShaderInst(ShaderDir);

	Uni_Inst_View = new UniTrans3D("View", *PolyInstShader);
	Multi_View = new MultiTrans3D("View");

	Uni_Inst_DepthFactors = new UniDepthFactors("DepthFactors", *PolyInstShader);
	Multi_DepthFactors = new MultiDepthFactors("DepthFactors");

	Uni_Inst_ViewPortSizeRatio = new UniSizeRatio2D("ViewPortSizeRatio", *PolyInstShader);
	Multi_ViewPortSizeRatio = new MultiSizeRatio2D("ViewPortSizeRatio");

	BaseShader * shaders [] = {
		PolyInstShader
	};
	int shader_count = 1;

	Multi_View -> FindUniforms(shaders, shader_count);
	Multi_DepthFactors -> FindUniforms(shaders, shader_count);
	Multi_ViewPortSizeRatio -> FindUniforms(shaders, shader_count);

	Multi_DepthFactors -> ChangeData(DepthFactors(0.1f, 1000.0f));
}
void FreeShaders()
{
	delete PolyInstShader;

	delete Uni_Inst_View;
	delete Multi_View;

	delete Uni_Inst_DepthFactors;
	delete Multi_DepthFactors;

	delete Uni_Inst_ViewPortSizeRatio;
	delete Multi_ViewPortSizeRatio;
}


void AddInstances()
{
	int j_len = 16;
	int i_len = 16;
	Entrys = new EntryContainerDynamic<PolyHedra_3D_InstData>::Entry*[j_len];
	for (int j = 0; j < j_len; j++)
	{
		Entrys[j] = PH_Instances -> Alloc(i_len);
		Point3D center = Point3D(
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

	Poly0 = YMT::PolyHedra::Cube();
	Tex0 = new TextureArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
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
	MoveFlatX(view_trans, win -> MoveFromKeys(2.0f * timeDelta));
	MoveFlatX(view_trans, win -> SpinFromCursor(0.2f * timeDelta));

	//if (glfwGetKey(win -> win, GLFW_KEY_R)) { tex_free(); tex_init(); }

	//test_trans.Rot.x += 1.0f * timeDelta;
	//test_trans.Rot.UpdateSinCos();

	Tex0 -> Bind();

	PolyInstShader -> Use();
	//PolyInstShader -> UniViewTrans.Value(view_trans);
	Multi_View -> ChangeData(view_trans);
	PH_Instances -> Update();
	PH_Instances -> Draw();
}

void Resize(int w, int h)
{
	//PolyInstShader -> WindowScale.Value(w, h);
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