#include <iostream>
#include "OpenGL/openGL.h"

#include "PolyHedra.hpp"
#include "Window.hpp"
#include "TextureArray.hpp"

#include "Graphics/PH/PH_3D/PolyHedra_3D_BufferArray.hpp"
#include "Graphics/PH/PH_3D/PolyHedra_3D_Shader.hpp"

#include "Graphics/Multiform/Data/UniSizeRatio2D.hpp"
#include "Graphics/Multiform/Data/UniTrans3D.hpp"
#include "Graphics/Multiform/Data/UniDepth.hpp"


#include "FileManager/FileContext.hpp"
#include "FileManager/DirectoryContext.hpp"



#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_HPP_TARGET_OPENCL_VERSION 200
#include <CL/opencl.hpp>



DirectoryContext ImageDir("../media/Images");
DirectoryContext ShaderDir("../media/Shaders");
DirectoryContext KernelDir("../media/Kernel");



Window * win;

YMT::PolyHedra * PH;
TextureArray * tex_arr;
PolyHedra_3D_BufferArray * PH_Buffer;
PolyHedra_3D_Shader * PH_Shader;

Trans3D view_trans;



unsigned int EntityCountX = 16;
unsigned int EntityCountY = 16;
unsigned int EntityCountZ = 16;
unsigned int EntityCount = EntityCountX * EntityCountY * EntityCountZ;

void CL_PrintError(cl_int err, bool printSuccess = false)
{
	if (err != CL_SUCCESS)
	{
		std::cout << "Error: " << err << "\n";
	}
	else if (printSuccess)
	{
		std::cout << "Succ\n";
	}
}

cl::Program CL_Program;

cl::SVMAllocator<Trans3D, cl::SVMTraitFine<>> SVM_Alloc;
unsigned int BufferSize = EntityCount * sizeof(Trans3D);
Trans3D * VMP_O;

cl::KernelFunctor<
	Trans3D *
> * Kernel_TransInit;

cl::KernelFunctor<
	Trans3D *
> * Kernel_TransSpinCenter;

void CL_Run_Init()
{
	cl_int err = CL_SUCCESS;
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
void CL_Run_SpinCenter()
{
	cl_int err = CL_SUCCESS;
	(*Kernel_TransSpinCenter)(
		cl::EnqueueArgs(
			cl::NDRange(EntityCount)
		),
		VMP_O,
		err
	);
	CL_PrintError(err);
	cl::finish();
}

void CL_Init()
{
	cl_int err = CL_SUCCESS;

	FileContext file = KernelDir.File("trans.cl");
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
			Trans3D *
		>(CL_Program, "TransInit", &err);
		CL_PrintError(err);
		Kernel_TransSpinCenter = new cl::KernelFunctor<
			Trans3D *
		>(CL_Program, "TransSpinCenter", &err);
		CL_PrintError(err);
	}
	catch(...)
	{
		std::cout << "Kernel Error\n";
		CL_PrintError(err);
	}

	VMP_O = SVM_Alloc.allocate(BufferSize);

	CL_Run_Init();
}
void CL_Free()
{
	delete Kernel_TransInit;
	delete Kernel_TransSpinCenter;

	SVM_Alloc.deallocate(VMP_O, BufferSize);
}



void Init()
{
	std::cout << "Init 0\n";

	tex_arr = new TextureArray(128, 128, 1, (FileContext[])
	{
		ImageDir.File("GrayDeant.png"),
	});

	PH = YMT::PolyHedra::ConeC(12, 0.5f);
	PH_Buffer = new PolyHedra_3D_BufferArray();
	{
		int count;
		PolyHedra_MainData * data = PH -> ToMainData(count);
		PH_Buffer -> BindMain(data, count);
		delete [] data;
	}

	win -> DefaultColor = Color(0.125f, 0.0f, 0.0f);

	Depth Depth;
	Depth.Factors = DepthFactors(0.1f, 100.0f);
	Depth.Range = Range(0.8f, 1.0f);
	Depth.Color = win -> DefaultColor;
	PH_Shader -> Depth.PutData(Depth);

	CL_Init();

	std::cout << "Init 1\n";
}
void Free()
{
	std::cout << "Free 0\n";

	delete tex_arr;
	delete PH;
	delete PH_Buffer;
	delete PH_Shader;

	CL_Free();

	std::cout << "Free 1\n";
}
void Frame(double timeDelta)
{
	view_trans.TransformFlatX(win -> MoveFromKeys(2.0f * timeDelta), win -> SpinFromCursor(0.2f * timeDelta));
	PH_Shader -> View.PutData(view_trans);
	tex_arr -> Bind();

	if (glfwGetKey(win -> win, GLFW_KEY_R))
	{
		delete tex_arr;
		tex_arr = new TextureArray(128, 128, 1, (FileContext[])
		{
			ImageDir.File("Orientation.png"),
		});
	}

	CL_Run_SpinCenter();

	PH_Buffer -> BindInst((const Simple3D_InstData *)VMP_O, EntityCount);
	PH_Buffer -> Draw();
}
void Resize(int w, int h)
{
	PH_Shader -> ViewPortSizeRatio.PutData(SizeRatio2D(w, h));
}



int main()
{
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

		PH_Shader = new PolyHedra_3D_Shader(ShaderDir);
		PH_Shader -> Use();
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
		view_trans = Trans3D(
			Point3D(0, 0, 0),
			Angle3D(0, 0, 0)
		);
	}



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}