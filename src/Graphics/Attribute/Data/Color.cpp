#include "Graphics/Attribute/Data/Color.hpp"
#include "DataStruct/Color.hpp"
#include "OpenGL/openGL.h"



Attribute::Color::Color(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexCol
) :
	Col(GL_FLOAT, sizeof(::Color), 3, divisor, stride, indexCol)
{ }



void Attribute::Color::Bind(const unsigned char * & offset) const
{
	Col.Bind(offset);
}
