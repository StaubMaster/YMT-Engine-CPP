
#ifndef  COLOR_HPP
# define COLOR_HPP

#include <sstream>

class Color
{
	public:
		float R;
		float G;
		float B;

	public:
		Color();
		Color(float r, float g, float b);
		Color(unsigned int rgb);

	public:
		unsigned int ToUInt32() const;
};

std::ostream & operator <<(std::ostream & o, const Color & val);

#endif
