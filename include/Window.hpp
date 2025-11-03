#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"
# include "DataStruct/Point2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

# include "Keys.hpp"

struct GLFWwindow;

struct Point3D;
struct Angle3D;

class Window
{
	private:
	public:
		GLFWwindow * win;
		KeyDataArrayArray Keys;

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

	private:
		SizeRatio2D ViewPortSizeRatio;
		Point2D Center;
	public:
		Color DefaultColor;

	public:
		Window(float w, float h);
		~Window();

	private:
		static void Callback_Error(int error, const char * decription);
		static void Callback_Resize(GLFWwindow * window, int w, int h);
		static void Callback_Key(GLFWwindow * window, int key, int scancode, int action, int mods);

	public:
		bool IsCursorLocked() const;
		void ToggleCursorLock();
		Point3D MoveFromKeys(float speed) const;
		Angle3D SpinFromCursor(float speed) const;
		Point2D CursorCentered() const;

	public:
		void Run();
		void Term();
};

#endif