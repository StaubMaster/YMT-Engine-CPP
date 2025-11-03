#include "Window.hpp"
#include "TimeMeasure.hpp"

#include "DataStruct/Point3D.hpp"
#include "DataStruct/Angle3D.hpp"
#include "DataStruct/Point2D.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



Window::Window(float w, float h) :
	win(NULL), Keys(7)
{
	Keys.KeyArrays[0] = KeyDataArray(32, 32);	//	Space
	Keys.KeyArrays[1] = KeyDataArray(48, 57);	//	Numbers
	Keys.KeyArrays[2] = KeyDataArray(65, 90);	//	Letters
	Keys.KeyArrays[3] = KeyDataArray(256, 269);	//	Control0
	Keys.KeyArrays[4] = KeyDataArray(290, 314);	//	Function
	Keys.KeyArrays[5] = KeyDataArray(320, 336);	//	KeyPad
	Keys.KeyArrays[6] = KeyDataArray(340, 348);	//	Control1

	glfwSetErrorCallback(Callback_Error);

	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
	glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
	glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	win = glfwCreateWindow(w, h, "YMT Window", NULL, NULL);
	if (win == NULL)
	{
		throw "Window Failed";
	}

	glfwMakeContextCurrent(win);

	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw "glad load GL-Loader Failed";
	}

	glfwSetWindowUserPointer(win, this);

	glfwSetFramebufferSizeCallback(win, Callback_Resize);
	glfwSetKeyCallback(win, Callback_Key);

	ShowFrameData = false;

	InitFunc = NULL;
	FrameFunc = NULL;
	FreeFunc = NULL;
	ResizeFunc = NULL;

	ViewPortSizeRatio = SizeRatio2D(w, h);
	Center = Point2D(w * 0.5f, h * 0.5f);
	DefaultColor = Color(0.5f, 0.5f, 0.5f);
}
Window::~Window()
{

}



void Window::Callback_Error(int error, const char * description)
{
	std::cerr << "GLFW Error: " << error << ": " << description << "\n";
}
void Window::Callback_Resize(GLFWwindow * window, int w, int h)
{
	Window * win = (Window *)glfwGetWindowUserPointer(window);
	glViewport(0, 0, w, h);
	win -> ViewPortSizeRatio = SizeRatio2D(w, h);
	win -> Center = Point2D(w * 0.5f, h * 0.5f);
	if (win -> ResizeFunc != NULL) { win -> ResizeFunc(w, h); }
}
void Window::Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window * win = (Window *)glfwGetWindowUserPointer(window);

	if (win -> Keys.Has(key))
	{
		KeyData & data = win -> Keys[key];
		if (action == GLFW_RELEASE)
		{
			data.State.SetReleased();
		}
		if (action == GLFW_PRESS)
		{
			data.State.SetPressed();
		}
	}

	(void)scancode;
	(void)mods;
}



bool Window::IsCursorLocked() const
{
	return (glfwGetInputMode(win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED);
}
void Window::ToggleCursorLock()
{
	int mode = glfwGetInputMode(win, GLFW_CURSOR);
	if (mode == GLFW_CURSOR_DISABLED)
	{
		glfwSetCursorPos(win, 0, 0);
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	else
	{
		glfwSetInputMode(win, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glfwSetCursorPos(win, 0, 0);
	}
}
Point3D Window::MoveFromKeys(float speed) const
{
	Point3D move;

	if (Keys[GLFW_KEY_A].State.GetDown())				{ move.X -= speed; }
	if (Keys[GLFW_KEY_D].State.GetDown())				{ move.X += speed; }
	if (Keys[GLFW_KEY_S].State.GetDown())				{ move.Z -= speed; }
	if (Keys[GLFW_KEY_W].State.GetDown())				{ move.Z += speed; }
	if (Keys[GLFW_KEY_SPACE].State.GetDown())			{ move.Y += speed; }
	if (Keys[GLFW_KEY_LEFT_SHIFT].State.GetDown())		{ move.Y -= speed; }
	if (Keys[GLFW_KEY_LEFT_CONTROL].State.GetDown())	{ move = move * 10; }

	return move;
}
Angle3D Window::SpinFromCursor(float speed) const
{
	Angle3D spin;

	double x, y;
	glfwGetCursorPos(win, &x, &y);

	spin.X = (+x) * speed;
	spin.Y = (-y) * speed;
	spin.Z = 0;

	return spin;
}
Point2D Window::CursorCentered() const
{
	if (IsCursorLocked()) { return Point2D(0, 0); }

	double x, y;
	glfwGetCursorPos(win, &x, &y);

	Point2D p;

	p.X = (x - Center.X);
	p.Y = (Center.Y - y);

	p.X = p.X / (ViewPortSizeRatio.W * ViewPortSizeRatio.RatioW);
	p.Y = p.Y / (ViewPortSizeRatio.H * ViewPortSizeRatio.RatioH);

	p.X = p.X * 2;
	p.Y = p.Y * 2;

	return p;
}



void Window::Run()
{
	try
	{
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LESS);
	glDepthRange(0, 1);
	glClearDepth(1.0f);

	int w, h;
	glfwGetFramebufferSize(win, &w, &h);

	int frameSkipped = 0;
	int frameCount = 0;
	TimeMeasure timeFunc;
	TimeMeasure timeSwap;
	TimeMeasure timePoll;

	if (InitFunc != NULL) { InitFunc(); }
	if (ResizeFunc != NULL) { ResizeFunc(w, h); }

	FrameTimeLast = glfwGetTime();
	while (!glfwWindowShouldClose(win))
	{
		double FrameTimeCurr = glfwGetTime();
		FrameTimeDelta = FrameTimeCurr - FrameTimeLast;
		if (FrameTimeDelta >= (1.0 / 64.0))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
			glClearColor(DefaultColor.R, DefaultColor.G, DefaultColor.B, 1.0f);

			if (Keys[GLFW_KEY_TAB].State.GetPressed())
			{
				ToggleCursorLock();
			}

			timeFunc.T0();
			FrameFunc(FrameTimeDelta);
			timeFunc.T1();

			timeSwap.T0();
			glfwSwapBuffers(win);
			timeSwap.T1();

			if (glfwGetInputMode(win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
			{
				glfwSetCursorPos(win, 0, 0);
			}

			Keys.Frame();

			timePoll.T0();
			glfwPollEvents();
			timePoll.T1();

			if (ShowFrameData)
			{
				if ((frameCount % 64) == 0)
				{
					std::cout << "Frame: " << frameCount << " (" << frameSkipped << ")" << "\n";
					std::cout << "FrameTime: " << ((1.0 / 64.0) * 1000) << "ms\n";
					std::cout << "Func: " << (timeFunc.Average() * 1000) << "ms\n";
					std::cout << "Swap: " << (timeSwap.Average() * 1000) << "ms\n";
					std::cout << "Poll: " << (timePoll.Average() * 1000) << "ms\n";
				}
				frameCount++;
				frameSkipped = 0;
			}
			FrameTimeLast = FrameTimeCurr;
		}
		else
		{
			frameSkipped++;
		}
	}
	}
	catch (std::exception & ex)
	{
		std::cout << "Exception: " << ex.what() << "\n";
	}
	catch (const char * err)
	{
		std::cerr << "String Error: "<< err << "\n";
	}
	catch (...)
	{
		std::cerr << "Unknown Error\n";
	}

	if (FreeFunc != NULL) { FreeFunc(); }
}
