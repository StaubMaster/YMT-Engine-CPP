#include "Graphics/Attribute/AttribPoint2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Attribute::Point2D::Point2D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(::Point2D), 2, divisor, stride, indexPos)
{ }



void Attribute::Point2D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
