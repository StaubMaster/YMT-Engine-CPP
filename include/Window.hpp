#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "../OpenGL/openGL.h"

# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Angle3D.hpp"

# include "Abstract2D/Point2D.hpp"

/*
	FrameTimeDelta
	FrameFunc

	InitFunc
	FreeFunc

	Cursor Center	lock/diff
	KeyChecks
*/

class Window
{
	private:
	public:
		GLFWwindow * win;

		void (*InitFunc)();
		void (*FrameFunc)(double);
		void (*FreeFunc)();

	private:
	public:
		double FrameTimeLast;
		double FrameTimeDelta;

	public:
		Window(float w, float h, void (*init)(), void (*frame)(double), void (*free)());
		~Window();

	private:
		static void Callback_Resize(GLFWwindow * window, int w, int h);
		static void Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods);

	public:
		Point3D MoveFromKeys(float speed);
		Angle3D SpinFromCursor(float speed);

	public:
		void Run();
		void Term();
};

#endif