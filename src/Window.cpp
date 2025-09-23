#include "Window.hpp"



Window::Window(float w, float h)
{
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

	InitFunc = NULL;
	FrameFunc = NULL;
	FreeFunc = NULL;
	ResizeFunc = NULL;
}
Window::~Window()
{

}



void Window::Callback_Resize(GLFWwindow * window, int w, int h)
{
	Window * win = (Window *)glfwGetWindowUserPointer(window);
	glViewport(0, 0, w, h);
	if (win -> ResizeFunc != NULL) { win -> ResizeFunc(w, h); }
}
void Window::Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	Window * win = (Window *)glfwGetWindowUserPointer(window);
	(void)win;

	if (key == GLFW_KEY_TAB && action == GLFW_PRESS)
	{
		int mode = glfwGetInputMode(window, GLFW_CURSOR);
		if (mode == GLFW_CURSOR_DISABLED)
		{
			glfwSetCursorPos(window, 0, 0);
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		else
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPos(window, 0, 0);
		}
	}

	(void)scancode;
	(void)action;
	(void)mods;
}



Point3D Window::MoveFromKeys(float speed)
{
	Point3D move;

	if (glfwGetInputMode(win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS) { move.X -= speed; }
		if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS) { move.X += speed; }
		if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS) { move.Z -= speed; }
		if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS) { move.Z += speed; }
		if (glfwGetKey(win, GLFW_KEY_SPACE) == GLFW_PRESS)      { move.Y += speed; }
		if (glfwGetKey(win, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) { move.Y -= speed; }
		if (glfwGetKey(win, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) { move = move * 10; }
	}

	return move;
}
Angle3D Window::SpinFromCursor(float speed)
{
	Angle3D spin;

	if (glfwGetInputMode(win, GLFW_CURSOR) == GLFW_CURSOR_DISABLED)
	{
		double x, y;
		glfwGetCursorPos(win, &x, &y);

		spin.x = (+x) * speed;
		spin.y = (-y) * speed;
		spin.UpdateSinCos();
	}

	return spin;
}


class TimeMeasure
{
	const int Limit = 1024;

	double * Memory;
	int Count;
	int Index;

	double TimeStamp;

	public:
	TimeMeasure()
	{
		Count = 0;
		Index = 0;
		Memory = new double[Limit];
	}
	~TimeMeasure()
	{
		delete [] Memory;
	}

	void T0()
	{
		TimeStamp = glfwGetTime();
	}
	void T1()
	{
		Memory[Index] = glfwGetTime() - TimeStamp;
		if (Index < Limit - 1) { Index++; } else { Index = 0; }
		if (Count < Limit - 1) { Count++; }
	}
	double Average()
	{
		double sum = 0;
		for (int i = 0; i < Count; i++)
		{
			sum += Memory[i];
		}
		return sum / Count;
	}
};

void Window::Run()
{
	if (InitFunc != NULL) { InitFunc(); }

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
	if (ResizeFunc != NULL) { ResizeFunc(w, h); }

	int frameMissed = 0;
	int frameCount = 0;
	TimeMeasure timeFunc;
	TimeMeasure timeSwap;
	TimeMeasure timePoll;

	while (!glfwWindowShouldClose(win))
	{
		double FrameTimeCurr = glfwGetTime();
		FrameTimeDelta = FrameTimeCurr - FrameTimeLast;
		if (FrameTimeDelta >= (1.0 / 64.0))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

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

			timePoll.T0();
			glfwPollEvents();
			timePoll.T1();

			if ((frameCount % 64) == 0)
			{
				std::cout << "Frame: " << frameCount << " (" << frameMissed << ")" << "\n";
				std::cout << "FrameTime: " << ((1.0 / 64.0) * 1000) << "ms\n";
				std::cout << "Func: " << (timeFunc.Average() * 1000) << "ms\n";
				std::cout << "Swap: " << (timeSwap.Average() * 1000) << "ms\n";
				std::cout << "Poll: " << (timePoll.Average() * 1000) << "ms\n";
			}
			FrameTimeLast = FrameTimeCurr;
			frameCount++;
			frameMissed = 0;
		}
		else
		{
			frameMissed++;
		}
	}

	if (FreeFunc != NULL) { FreeFunc(); }
}
