#include <iostream>
#include "../OpenGL/openGL.h"

#include "Graphics/BaseShader.hpp"
#include "Graphics/Uniform/Float/UniTransformation3D.hpp"
#include "Graphics/Uniform/Float/UniDepth.hpp"
#include "Graphics/Uniform/Float/UniScale.hpp"

#include "Abstract3D/Point3D.hpp"
#include "Abstract3D/Angle3D.hpp"
#include "Abstract3D/Transformation3D.hpp"

#include "Abstract2D/Point2D.hpp"

#include "Window.hpp"

#include "PolyHedra.hpp"
#include "PolyHedraBuffer.hpp"



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
UniDepth * Depth;
UniScale * WindowScale;

PolyHedra * MainPoly;



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
	MoveFlatX(view_trans, win -> MoveFromKeys(2.0f * timeDelta));
	MoveFlatX(view_trans, win -> SpinFromCursor(0.2f * timeDelta));

	test_trans.Rot.x += 1.0f * timeDelta;
	test_trans.Rot.UpdateSinCos();

	int w, h;
	glfwGetFramebufferSize(win -> win, &w, &h);

	testShader -> Use();
	WindowScale -> Value(w, h);
	Depth -> Value(0.1f, 10.0f);
	UniTrans -> Value(test_trans);
	UniViewTrans -> Value(view_trans);

	MainPoly -> Draw();
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
	Depth = new UniDepth(testShader, "depthFactor");
	WindowScale = new UniScale(testShader, "contentScale");



	MainPoly = PolyHedra::Cube();
	MainPoly -> ToBuffer();



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
	delete Depth;

	delete WindowScale;

	delete MainPoly;

	delete win;



	glfwTerminate();
	return 0;
}