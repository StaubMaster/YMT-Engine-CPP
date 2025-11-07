#include "Graphics/Attribute/Data/Angle3D.hpp"
#include "DataStruct/Angle3D.hpp"
#include "OpenGL/openGL.h"

#include <iostream>



Attribute::Angle3D::Angle3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Location0(3, divisor, stride, index + 0),
	Location1(3, divisor, stride, index + 1),
	Location2(3, divisor, stride, index + 2)
{ }



void Attribute::Angle3D::Bind(const unsigned char * & offset) const
{
	offset += sizeof(float) * 3;
	Location0.Bind(offset);
	Location1.Bind(offset);
	Location2.Bind(offset);
}
