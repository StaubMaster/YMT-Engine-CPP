#include <iostream>
#include "../OpenGL/openGL.h"

#include "../include/Graphics/BaseShader.hpp"
#include "../include/Graphics/PosColBuffer.hpp"

#include "../include/Abstract3D/Point3D.hpp"
#include "../include/Abstract3D/Angle3D.hpp"

#include "../include/Abstract2D/Point2D.hpp"
#include "../include/PolyHedra.hpp"

int main(void)
{
	GLFWwindow* window;

	if (glfwInit() == 0)
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwTerminate();
		return -1;
	}

	BaseShader * testShader;

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

	unsigned int UniTrans = testShader -> UniformFind("trans");

	PosColBuffer * testBuffer = new PosColBuffer();

	{
		float test_data[] {
			-1, -1, -1,		0.0f, 0.0f,
			+1, -1, -1,		1.0f, 0.0f,
			-1, +1, -1,		0.0f, 1.0f,

			-1, -1, -1,		0.0f, 0.0f,
			-1, +1, -1,		1.0f, 0.0f,
			-1, -1, +1,		0.0f, 1.0f,

			-1, -1, -1,		0.0f, 0.0f,
			-1, -1, +1,		1.0f, 0.0f,
			+1, -1, -1,		0.0f, 1.0f,

			+1, +1, +1,		1.0f, 1.0f,
			-1, +1, +1,		1.0f, 0.0f,
			+1, -1, +1,		0.0f, 1.0f,

			+1, +1, +1,		1.0f, 1.0f,
			+1, -1, +1,		1.0f, 0.0f,
			+1, +1, -1,		0.0f, 1.0f,

			+1, +1, +1,		1.0f, 1.0f,
			+1, +1, -1,		1.0f, 0.0f,
			-1, +1, +1,		0.0f, 1.0f,
		};
		testBuffer -> Data(18, test_data);
	}

	Point3D test_Pos = Point3D(0, 0, 3);
	Angle3D test_Rot = Angle3D(0, 0, 0);

	double	FrameTimeLast = glfwGetTime();
	double	FrameTimeCurr;
	double	FrameTimeDelta;

	while (!glfwWindowShouldClose(window))
	{
		FrameTimeCurr = glfwGetTime();
		FrameTimeDelta = FrameTimeCurr - FrameTimeLast;
		FrameTimeLast = FrameTimeCurr;

		test_Rot.x += 1.0f * FrameTimeDelta;
		test_Rot.UpdateSinCos();

		glClear(GL_COLOR_BUFFER_BIT);

		testShader -> Use();
		float trans[9] = {
			test_Pos.X, test_Pos.Y, test_Pos.Z,
			test_Rot.sin_x, test_Rot.sin_y, test_Rot.sin_z,
			test_Rot.cos_x, test_Rot.cos_y, test_Rot.cos_z,
		};
		glUniform3fv(UniTrans, 9, trans);

		testBuffer -> Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete testBuffer;

	delete testShader;

	glfwTerminate();
	return 0;
}