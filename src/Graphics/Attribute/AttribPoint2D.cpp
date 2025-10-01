#include "Graphics/Attribute/AttribPoint2D.hpp"
#include "Data/2D/Point2D.hpp"
#include "OpenGL/openGL.h"



AttribPoint2D::AttribPoint2D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(Point2D), 2, divisor, stride, indexPos)
{ }



void AttribPoint2D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
