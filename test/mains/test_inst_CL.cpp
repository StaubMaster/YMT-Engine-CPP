#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract.hpp"
#include "PolyHedra.hpp"
#include "Window.hpp"
#include "TextureArray.hpp"
#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"



#include "FileManager/FileContext.hpp"
#include "FileManager/DirectoryContext.hpp"



#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200
#include <CL/opencl.hpp>

DirectoryContext ImageDir("../media/Images");

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

YMT::PolyHedra::ShaderInst * PolyInstShader;
YMT::PolyHedra * PH;
PolyHedra_3D_Buffer * PH_Buffer;
TextureArray * tex_arr;



Transformation3D view_trans;



unsigned int EntityCountX = 4;
unsigned int EntityCountY = 4;
unsigned int EntityCountZ = 4;
unsigned int EntityCount = EntityCountX * EntityCountY * EntityCountZ;

void CL_PrintError(cl_int err)
{
	if (err != CL_SUCCESS)
	{
		std::cout << "Error: " << err << "\n";
	}
	else
	{
		std::cout << "Succ\n";
	}
}

cl::Program CL_Program;

cl::SVMAllocator<Transformation3D, cl::SVMTraitFine<>> SVM_Alloc;
unsigned int BufferSize = EntityCount * sizeof(Transformation3D);
Transformation3D * VMP_O;

cl::KernelFunctor<
	Transformation3D *
> * Kernel_TransInit;

cl::KernelFunctor<
	Transformation3D *
> * Kernel_TransSpinCenter;

void CL_Init()
{
	cl_int err = CL_SUCCESS;

	FileContext file("../media/trans.cl");
	std::string file_text = file.LoadText();
	CL_Program = cl::Program(file_text);
	try
	{
		CL_Program.build("-cl-std=CL2.0");
	}
	catch (...)
	{
		cl::BuildLogType buildInfo = CL_Program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(&err);
		CL_PrintError(err);
		for (std::pair<cl::Device, std::string> &pair : buildInfo)
		{
			std::cerr << pair.second << std::endl << std::endl;
		}
	}

	try
	{
		Kernel_TransInit = new cl::KernelFunctor<
			Transformation3D *
		>(CL_Program, "TransInit", &err);
		CL_PrintError(err);
		Kernel_TransSpinCenter = new cl::KernelFunctor<
			Transformation3D *
		>(CL_Program, "TransSpinCenter", &err);
		CL_PrintError(err);
	}
	catch(...)
	{
		std::cout << "Kernel Error\n";
		CL_PrintError(err);
	}

	VMP_O = SVM_Alloc.allocate(BufferSize);

	err = CL_SUCCESS;
	(*Kernel_TransInit)(
		cl::EnqueueArgs(
			cl::NDRange(EntityCountX, EntityCountY, EntityCountZ)
		),
		VMP_O,
		err
	);
	CL_PrintError(err);
	cl::finish();
}
void CL_Free()
{
	delete Kernel_TransInit;
	delete Kernel_TransSpinCenter;

	SVM_Alloc.deallocate(VMP_O, BufferSize);
}
void CL_Frame()
{
	cl_int err = CL_SUCCESS;
	/*(*Kernel_TransInit)(
		cl::EnqueueArgs(
			cl::NDRange(EntityCount)
		),
		VMP_O,
		err
	);*/
	(*Kernel_TransSpinCenter)(
		cl::EnqueueArgs(
			cl::NDRange(EntityCount)
		),
		VMP_O,
		err
	);
	//CL_PrintError(err);
	cl::finish();
}



void Init()
{
	std::cout << "Init 0\n";
	tex_arr = new TextureArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("Orientation.png"),
	});
	CL_Init();
	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";
	delete tex_arr;
	CL_Free();
	std::cout << "Free 1\n";
}
void Frame(double timeDelta)
{
	MoveFlatX(view_trans, win -> MoveFromKeys(2.0f * timeDelta));
	MoveFlatX(view_trans, win -> SpinFromCursor(0.2f * timeDelta));

	if (glfwGetKey(win -> win, GLFW_KEY_R))
	{
		delete tex_arr;
		tex_arr = new TextureArray(128, 128, 1, (FileContext[])
		{
			ImageDir.File("Orientation.png"),
		});
	}

	//test_trans.Rot.x += 1.0f * timeDelta;
	//test_trans.Rot.UpdateSinCos();

	CL_Frame();

	//PolyInstBuffer -> DataTrans(EntityCount, VMP_O);
	PH_Buffer -> BindInst((const PolyHedra_3D_InstData *)VMP_O, EntityCount);

	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D_ARRAY, tex_arr);
	tex_arr -> Bind();

	PolyInstShader -> Use();
	//PolyInstShader -> UniViewTrans.Value(view_trans);
	//PolyInstBuffer -> Draw();
	PH_Buffer -> Draw();
}

void Resize(int w, int h)
{
	//PolyInstShader -> WindowScale.Value(w, h);
	(void)w;
	(void)h;
}



int main()
{
	std::cout << "!!!!!!!!!!!!!!!!\n";
	std::cout << "Old Uniforms have been removed and need to be replaced\n";
	std::cout << "!!!!!!!!!!!!!!!!\n";
	return 0;

	if (glfwInit() == 0)
	{
		std::cout << "Init Failed\n";
		return -1;
	}



	try
	{
		win = new Window(640, 480);
		win -> InitFunc = Init;
		win -> FrameFunc = Frame;
		win -> FreeFunc = Free;
		win -> ResizeFunc = Resize;

		PolyInstShader = new YMT::PolyHedra::ShaderInst();
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

	{
		float near = 0.1f;
		float far = 1000.0f;
		//PolyInstShader -> Depth.Value(near, far);
		(void)near;
		(void)far;

		view_trans = Transformation3D(
			Point3D(0, 0, 0),
			Angle3D(0, 0, 0)
		);
	}

	{
		PH = YMT::PolyHedra::Cube();
		PH_Buffer = new PolyHedra_3D_Buffer();
		int count;
		PolyHedra_MainData * data = PH -> ToMainData(count);
		PH_Buffer -> BindMain(data, count);
		delete [] data;
	}



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete PH;
	delete PH_Buffer;
	delete PolyInstShader;

	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}