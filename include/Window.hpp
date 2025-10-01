#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"

struct GLFWwindow;

class Point3D;
class Angle3D;
class Point2D;

class Window
{
	private:
	public:
		GLFWwindow * win;

	public:
		bool ShowFrameData;
	private:
		double FrameTimeLast;
		double FrameTimeDelta;

	public:
		void (*InitFunc)();
		void (*FrameFunc)(double);
		void (*FreeFunc)();
		void (*ResizeFunc)(int, int);

	public:
		Color DefaultColor;

	public:
		Window(float w, float h);
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