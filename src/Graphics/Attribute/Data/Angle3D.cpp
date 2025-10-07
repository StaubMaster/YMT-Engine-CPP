#include "Graphics/Attribute/Data/Angle3D.hpp"
#include "OpenGL/openGL.h"



Attribute::Angle3D::Angle3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Location(GL_FLOAT, sizeof(float) * 3 * 3, 3 * 3, divisor, stride, index)
{ }



void Attribute::Angle3D::Bind(const unsigned char * & offset) const
{
	offset += sizeof(float) * 3;
	Location.Bind(offset);
}
