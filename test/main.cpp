#include <iostream>
#include "OpenGL/openGL.h"

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
#include "PolyHedraShader.hpp"
#include "PolyHedraInstBuffer.hpp"
#include "PolyHedraInstShader.hpp"

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

PolyHedraShader * PolyShader;
PolyHedraInstShader * PolyInstShader;
PolyHedraInstBuffer * PolyInstBuffer;
PolyHedra * Poly0;

unsigned int tex_arr;



Transformation3D test_trans;
Transformation3D view_trans;

Transformation3D * TransArr;
unsigned int TransNum;



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

	//test_trans.Rot.x += 1.0f * timeDelta;
	//test_trans.Rot.UpdateSinCos();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D_ARRAY, tex_arr);

	PolyShader -> Use();
	PolyShader -> UniTrans.Value(test_trans);
	PolyShader -> UniViewTrans.Value(view_trans);
	Poly0 -> Draw();

	PolyInstShader -> Use();
	PolyInstShader -> UniViewTrans.Value(view_trans);
	PolyInstBuffer -> Draw();
}

void Resize(int w, int h)
{
	PolyShader -> WindowScale.Value(w, h);
	PolyInstShader -> WindowScale.Value(w, h);
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
		win = new Window(640, 480);
		win -> InitFunc = Init;
		win -> FrameFunc = Frame;
		win -> FreeFunc = Free;
		win -> ResizeFunc = Resize;

		PolyShader = new PolyHedraShader();
		PolyInstShader = new PolyHedraInstShader();
	}
	catch (std::exception & ex)
	{
		std::cout << "exception: " << ex.what() << "\n";
		PolyShader = NULL;
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
		float far = 10.0f;
		PolyShader -> Depth.Value(near, far);
		PolyInstShader -> Depth.Value(near, far);
	}

	Poly0 = PolyHedra::Cube();
	Poly0 -> ToBuffer();
	PolyInstBuffer = new PolyHedraInstBuffer();
	Poly0 -> ToBuffer(*PolyInstBuffer);

	{
		glGenTextures(1, &tex_arr);
		glBindTexture(GL_TEXTURE_2D_ARRAY, tex_arr);
		
		int tex_count = 1;
		int tex_w = 128;
		int tex_h = 128;

		glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, tex_w, tex_h, tex_count, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, NULL);

		int i = 0;
		{
			PNG_Image * img = PNG_Image::Load(std::string(IMAGE_DIR) + "Orientation.png");
			PNG_Image * scaled = img -> Scale(tex_w, tex_h);
			glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, tex_w, tex_h, 1, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, scaled -> data);
		}

		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
	}



	test_trans = Transformation3D(
		Point3D(2, 2, 2),
		Angle3D(0, 0, 0)
	);

	view_trans = Transformation3D(
		Point3D(0, 0, 0),
		Angle3D(0, 0, 0)
	);

	TransArr = new Transformation3D[4]
	{
		Transformation3D(Point3D(0, 0, 0), Angle3D(0, 0, 0)),
		Transformation3D(Point3D(2, 3, 4), Angle3D(1, 2, 3)),
		Transformation3D(Point3D(3, 0, 0), Angle3D(1, 0, 0)),
		Transformation3D(Point3D(0, 0, 2), Angle3D(0, 0, 1)),
	};
	TransNum = 4;
	PolyInstBuffer -> DataTrans(TransNum, TransArr);



	std::cout << "++++ Run\n";
	win -> Run();
	std::cout << "---- Run\n";



	glDeleteTextures(1, &tex_arr);

	delete Poly0;
	delete PolyShader;

	delete PolyInstShader;
	delete PolyInstBuffer;
	delete [] TransArr;

	delete win;



	glfwTerminate();
	std::cout << "main() return";
	return 0;
}