#include <iostream>
#include "OpenGL/openGL.h"

#include "Abstract3D/Point3D.hpp"
#include "Abstract3D/Angle3D.hpp"
#include "Abstract3D/Transformation3D.hpp"

#include "Abstract2D/Point2D.hpp"

#include "PolyHedra.hpp"
#include "PolyHedraBuffer.hpp"
#include "PolyHedraShader.hpp"
#include "PolyHedraInstBuffer.hpp"
#include "PolyHedraInstShader.hpp"

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

PolyHedraInstShader * PolyInstShader;
PolyHedraInstBuffer * PolyInstBuffer;
PolyHedra * Poly0;

Transformation3D view_trans;

Transformation3D * TransArr;
unsigned int TransNum;



unsigned int tex_arr;
void tex_init()
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
void tex_free()
{
	glDeleteTextures(1, &tex_arr);
}



void Init()
{
	std::cout << "Init 0\n";
	tex_init();
	std::cout << "Init 1\n";
}

void Free()
{
	std::cout << "Free 0\n";
	tex_free();
	std::cout << "Free 1\n";
}

void Frame(double timeDelta)
{
	MoveFlatX(view_trans, win -> MoveFromKeys(2.0f * timeDelta));
	MoveFlatX(view_trans, win -> SpinFromCursor(0.2f * timeDelta));

	if (glfwGetKey(win -> win, GLFW_KEY_R)) { tex_free(); tex_init(); }

	//test_trans.Rot.x += 1.0f * timeDelta;
	//test_trans.Rot.UpdateSinCos();

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D_ARRAY, tex_arr);

	PolyInstShader -> Use();
	PolyInstShader -> UniViewTrans.Value(view_trans);
	PolyInstBuffer -> Draw();
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

		PolyInstShader = new PolyHedraInstShader();
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
		Poly0 = PolyHedra::Cube();
		PolyInstBuffer = new PolyHedraInstBuffer();
		Poly0 -> ToBuffer(*PolyInstBuffer);
	}



	TransNum = 800000;
	TransArr = new Transformation3D[TransNum];
	for (unsigned int i = 0; i < TransNum; i++)
	{
		TransArr[i].Pos = Point3D(
			(std::rand() & 0x1FF) - 0xFF,
			(std::rand() & 0x1FF) - 0xFF,
			(std::rand() & 0x1FF) - 0xFF
		);
	}
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