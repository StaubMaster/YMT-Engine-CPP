#include <iostream>
#include "../OpenGL/openGL.h"

#include "Graphics/BaseShader.hpp"
#include "Graphics/PosColBuffer.hpp"
#include "Graphics/Uniform/Float/UniTransformation3D.hpp"

#include "Abstract3D/Point3D.hpp"
#include "Abstract3D/Angle3D.hpp"
#include "Abstract3D/Transformation3D.hpp"

#include "Abstract2D/Point2D.hpp"

#include "PolyHedra.hpp"
#include "Window.hpp"



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

BaseShader * testShader;
UniTransformation3D * UniTrans;
UniTransformation3D * UniViewTrans;

PosColBuffer * testBuffer;



Transformation3D test_trans;
Transformation3D view_trans;



void Init()
{
	std::cout << "Init 0\n";
	std::cout << "Init 1\n";
}

void Free()
{
	std::cout << "Free 0\n";
	std::cout << "Free 1\n";
}

void Frame(double timeDelta)
{
	MoveFlatX(view_trans, win -> MoveFromKeys(1.0f * timeDelta));
	MoveFlatX(view_trans, win -> SpinFromCursor(0.2f * timeDelta));

	//test_trans.Rot.x += 1.0f * timeDelta;
	//test_trans.Rot.UpdateSinCos();

	glClear(GL_COLOR_BUFFER_BIT);

	testShader -> Use();
	UniTrans -> Value(test_trans);
	UniViewTrans -> Value(view_trans);

	testBuffer -> Draw();
}



int main(void)
{
	if (glfwInit() == 0)
	{
		std::cout << "Init Failed\n";
		return -1;
	}



	try
	{
		win = new Window(640, 480, Init, Frame, Free);
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



	try
	{
		const ShaderCode * test_code[2] = {
			ShaderCode::FromFile("Shaders/test.vert"),
			ShaderCode::FromFile("Shaders/test.frag"),
		};
		testShader = new BaseShader(test_code, 2);
		delete test_code[0];
		delete test_code[1];
	}
	catch (std::exception & ex)
	{
		std::cout << "exception: " << ex.what() << "\n";
		testShader = NULL;
	}
	catch (...)
	{
		std::cout << "Unknown\n";
		testShader = NULL;
	}
	UniTrans = new UniTransformation3D(testShader, "trans");
	UniViewTrans = new UniTransformation3D(testShader, "view");



	testBuffer = new PosColBuffer();
	{
		float test_data[] {
			-1, -1, -1,		0.0f, 0.0f, 0.0f,
			+1, -1, -1,		1.0f, 0.0f, 0.0f,
			-1, +1, -1,		0.0f, 1.0f, 0.0f,

			-1, -1, -1,		0.0f, 0.0f, 0.0f,
			-1, +1, -1,		0.0f, 1.0f, 0.0f,
			-1, -1, +1,		0.0f, 0.0f, 1.0f,

			-1, -1, -1,		0.0f, 0.0f, 0.0f,
			-1, -1, +1,		0.0f, 0.0f, 1.0f,
			+1, -1, -1,		1.0f, 0.0f, 0.0f,

			-1, +1, +1,		0.0f, 1.0f, 1.0f,
			+1, -1, +1,		1.0f, 0.0f, 1.0f,
			+1, +1, +1,		1.0f, 1.0f, 1.0f,

			+1, -1, +1,		1.0f, 0.0f, 1.0f,
			+1, +1, -1,		1.0f, 1.0f, 0.0f,
			+1, +1, +1,		1.0f, 1.0f, 1.0f,

			+1, +1, -1,		1.0f, 1.0f, 0.0f,
			-1, +1, +1,		0.0f, 1.0f, 1.0f,
			+1, +1, +1,		1.0f, 1.0f, 1.0f,
		};
		testBuffer -> Data(18, test_data);
	}



	test_trans = Transformation3D(
		Point3D(0, 0, 0),
		Angle3D(0, 0, 0)
	);

	view_trans = Transformation3D(
		Point3D(0, 0, 0),
		Angle3D(0, 0, 0)
	);



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	delete testShader;
	delete UniTrans;
	delete UniViewTrans;

	delete testBuffer;

	delete win;



	glfwTerminate();
	return 0;
}