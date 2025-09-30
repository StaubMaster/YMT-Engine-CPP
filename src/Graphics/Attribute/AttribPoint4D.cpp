#include "Graphics/Attribute/AttribPoint4D.hpp"

#include "OpenGL/openGL.h"
#include "Abstract.hpp"



AttribPoint4D::AttribPoint4D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(Point3D), 3, divisor, stride, indexPos)
{ }



void AttribPoint4D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
