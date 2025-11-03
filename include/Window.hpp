#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "DataStruct/Color.hpp"
# include "DataStruct/Point2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

struct GLFWwindow;

struct Point3D;
struct Angle3D;

/*
store an Array of Keystates
to determin Up:Down:Pressed:Released of Keys

putting everything would be a lot of empty space
put into arrays whereever possible

48 to 57	Numbers
65 to 90	Letters
256 to 269	Control0
280 to 284	Locks (and other)
290 to 314	Function
320 to 336	KeyPad
340 to 348	Control1

automatically create arrays
these wont ever change so nah
*/

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
		bool IsMouseLocked() const;
		Point3D MoveFromKeys(float speed) const;
		Angle3D SpinFromCursor(float speed) const;
		Point2D CursorCentered() const;

	public:
		void Run();
		void Term();
};

#endif