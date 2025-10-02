#include "Graphics/Attribute/Data/Point3D.hpp"
#include "DataStruct/Point3D.hpp"
#include "OpenGL/openGL.h"



Attribute::Point3D::Point3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Pos(GL_FLOAT, sizeof(::Point3D), 3, divisor, stride, indexPos)
{ }



void Attribute::Point3D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
}
