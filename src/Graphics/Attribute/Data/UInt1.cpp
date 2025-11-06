#include "Graphics/Attribute/Data/UInt1.hpp"
#include "OpenGL/openGL.h"



Attribute::UInt1::UInt1(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Location(GL_UNSIGNED_INT, sizeof(unsigned int) * 1, 1, divisor, stride, index)
{ }



void Attribute::UInt1::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
