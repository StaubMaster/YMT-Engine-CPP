#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract3D/Point3D.hpp"
#include "Abstract3D/Angle3D.hpp"
#include "Abstract3D/Transformation3D.hpp"

#include "Abstract2D/Point2D.hpp"

#include "PolyHedra.hpp"
#include "PolyHedra/ShaderInst.hpp"
#include "PolyHedra/BufferInst.hpp"
#include "TextureArray.hpp"

#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"
#include "Graphics/Buffer/PolyHedra_3D_InstData.hpp"

#include "Window.hpp"

#include "FileParse/PNG/PNG_Image.hpp"



#define IMAGE_DIR "../media/Images/"



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

PolyHedra_3D_Buffer * PH_Buffer;
YMT::PolyHedra::ShaderInst * PolyInstShader;
YMT::PolyHedra::BufferInst * PolyInstBuffer;
YMT::PolyHedra * Poly0;
TextureArray * Tex0;



Transformation3D view_trans;

PolyHedra_3D_InstData * InstData;
int InstCount;

Transformation3D * TransArr;
unsigned int TransNum;



void Init()
{
	std::cout << "Init 0\n";

	Tex0 = new TextureArray(128, 128, 1, (std::string[])
	{
		std::string(IMAGE_DIR) + "Orientation.png",
	});

	PH_Buffer = new PolyHedra_3D_Buffer();

	int main_count;
	RenderPoint3D * main_data = Poly0 -> ToBufferData(main_count);
	PH_Buffer -> BindMain(main_data, main_count);
	delete [] main_data;

	InstData = new PolyHedra_3D_InstData[TransNum];
	for (unsigned int i = 0; i < TransNum; i++)
	{
		InstData[i] = PolyHedra_3D_InstData(TransArr[i]);
	}
	InstCount = TransNum;
	PH_Buffer -> BindInst(InstData, InstCount);

	std::cout << "Init 1\n";
}

void Free()
{
	std::cout << "Free 0\n";

	delete Tex0;
	delete PH_Buffer;
	delete [] InstData;

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
	PolyInstShader -> UniViewTrans.Value(view_trans);
	//PolyInstBuffer -> Draw();
	PH_Buffer -> Draw();
}

void Resize(int w, int h)
{
	PolyInstShader -> WindowScale.Value(w, h);
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
		PolyInstShader -> Depth.Value(near, far);

		view_trans = Transformation3D(
			Point3D(0, 0, 0),
			Angle3D(0, 0, 0)
		);
	}

	{
		Poly0 = YMT::PolyHedra::Cube();
		PolyInstBuffer = new YMT::PolyHedra::BufferInst();
		Poly0 -> ToInst(*PolyInstBuffer);
	}

	TransNum = 800000;
	//TransNum = 3;
	TransArr = new Transformation3D[TransNum];
	for (unsigned int i = 0; i < TransNum; i++)
	{
		TransArr[i].Pos = Point3D(
			(std::rand() & 0x1FF) - 0xFF,
			(std::rand() & 0x1FF) - 0xFF,
			(std::rand() & 0x1FF) - 0xFF
		);
	}
	TransArr[0].Pos = Point3D( 0, 0, +1);
	TransArr[1].Pos = Point3D(-1, 0, -1);
	TransArr[2].Pos = Point3D(+1, 0, -1);
	std::cout << "Count: " << TransNum << "\n";
	int MemSize = TransNum * sizeof(Transformation3D);
	std::cout << (MemSize / (1)) << " Bytes\n";
	std::cout << (MemSize / (1 * 1000)) << "k Bytes\n";
	std::cout << (MemSize / (1 * 1000 * 1000)) << "M Bytes\n";
	PolyInstBuffer -> DataTrans(TransNum, TransArr);

	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete Poly0;
	delete PolyInstShader;
	delete PolyInstBuffer;
	delete [] TransArr;

	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}