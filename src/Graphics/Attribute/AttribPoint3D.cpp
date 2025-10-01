#include "Graphics/Attribute/AttribPoint3D.hpp"
#include "Data/3D/Point3D.hpp"
#include "OpenGL/openGL.h"



AttribPoint3D::AttribPoint3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(Point3D), 3, divisor, stride, indexPos)
{ }



void AttribPoint3D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
