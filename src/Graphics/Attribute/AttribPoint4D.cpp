#include "Graphics/Attribute/AttribPoint4D.hpp"
#include "Data/4D/Point4D.hpp"
#include "OpenGL/openGL.h"



AttribPoint4D::AttribPoint4D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(Point4D), 4, divisor, stride, indexPos)
{ }



void AttribPoint4D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
