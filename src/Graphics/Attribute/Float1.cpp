#include "Graphics/Attribute/Float1.hpp"
#include "OpenGL/openGL.h"



Attribute::Float1::Float1(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Location(GL_FLOAT, sizeof(float) * 1, 1, divisor, stride, index)
{ }



void Attribute::Float1::Bind(const unsigned char * & offset) const
{
	Location.Bind(offset);
}
