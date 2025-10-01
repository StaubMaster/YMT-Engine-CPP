#include "Data/Color.hpp"



Color::Color()
{
	R = 0.0f;
	G = 0.0f;
	B = 0.0f;
}
Color::Color(float r, float g, float b)
{
	R = r;
	G = g;
	B = b;
}
Color::Color(unsigned int rgb)
{
	R = ((rgb >> 0x10) & 0xFF) / 255.0f;
	G = ((rgb >> 0x08) & 0xFF) / 255.0f;
	B = ((rgb >> 0x00) & 0xFF) / 255.0f;
}



unsigned int Color::ToUInt32() const
{
	unsigned char r = R * 255.0f;
	unsigned char g = G * 255.0f;
	unsigned char b = B * 255.0f;
	return ((r << 0x10) | (g << 0x08) | (b << 0x00));
}
