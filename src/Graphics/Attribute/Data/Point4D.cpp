#include "Graphics/Attribute/Data/Point4D.hpp"
#include "DataStruct/Point4D.hpp"
#include "OpenGL/openGL.h"



Attribute::Point4D::Point4D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(::Point4D), 4, divisor, stride, indexPos)
{ }



void Attribute::Point4D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
