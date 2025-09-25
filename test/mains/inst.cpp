#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract3D/Point3D.hpp"
#include "Abstract3D/Angle3D.hpp"
#include "Abstract3D/Transformation3D.hpp"

#include "Abstract2D/Point2D.hpp"

#include "PolyHedra.hpp"
#include "PolyHedra/ShaderInst.hpp"
#include "TextureArray.hpp"

#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"

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

YMT::PolyHedra * Poly0;
YMT::PolyHedra::ShaderInst * PolyInstShader;
TextureArray * Tex0;

PolyHedra_3D_Buffer * PH_Buffer;


Transformation3D view_trans;



void Init()
{
	std::cout << "Init 0\n";

	Tex0 = new TextureArray(128, 128, 1, (std::string[])
	{
		std::string(IMAGE_DIR) + "Orientation.png",
	});

	std::cout << "Init 1\n";
}

void Free()
{
	std::cout << "Free 0\n";

	delete Tex0;
	delete PH_Buffer;

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
	PH_Buffer -> Update();
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
	}

	PH_Buffer = new PolyHedra_3D_Buffer();
	{
		int main_count;
		PolyHedra_MainData * main_data = Poly0 -> ToMainData(main_count);
		PH_Buffer -> BindMain(main_data, main_count);
		delete [] main_data;
	}

	EntryContainerDynamic<PolyHedra_3D_InstData>::Entry * TestInst = PH_Buffer -> Instances.Alloc(3);
	(*TestInst)[0].Trans.Pos = Point3D( 0, 0, +1);
	(*TestInst)[1].Trans.Pos = Point3D(-1, 0, -1);
	(*TestInst)[2].Trans.Pos = Point3D(+1, 0, -1);

	int j_len = 16;
	int i_len = 16;
	EntryContainerDynamic<PolyHedra_3D_InstData>::Entry ** Entrys = new EntryContainerDynamic<PolyHedra_3D_InstData>::Entry*[j_len];
	for (int j = 0; j < j_len; j++)
	{
		Entrys[j] = PH_Buffer -> Instances.Alloc(i_len);
		Point3D center = Point3D(
			(std::rand() & 0x8F) - 0x7F,
			(std::rand() & 0x8F) - 0x7F,
			(std::rand() & 0x8F) - 0x7F
		);
		std::cout << "Center: " << center.X << " " << center.Y << " " << center.Z << "\n";
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
		int MemSize = (PH_Buffer -> Instances.Length) * sizeof(PolyHedra_3D_InstData);
		std::cout << "Count: " << (PH_Buffer -> Instances.Length) << "\n";
		std::cout << (MemSize / (1)) << " Bytes\n";
		std::cout << (MemSize / (1 * 1000)) << "k Bytes\n";
		std::cout << (MemSize / (1 * 1000 * 1000)) << "M Bytes\n";
	}

	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";

	std::cout << "Dispose Test\n";
	//TestInst -> Dispose();
	std::cout << "Dispose Entrys\n";
	for (int j = 0; j < j_len; j++)
	{
		//Entrys[j] -> Dispose();
	}
	std::cout << "Dispose Done\n";
	delete [] Entrys;

	delete Poly0;
	delete PolyInstShader;

	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}