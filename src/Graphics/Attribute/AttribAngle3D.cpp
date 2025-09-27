#include "Graphics/Attribute/AttribAngle3D.hpp"
#include "OpenGL/openGL.h"
#include "Abstract.hpp"



AttribAngle3D::AttribAngle3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexSin,
	unsigned int indexCos
) :
	Sin(GL_FLOAT, sizeof(float) * 3, 3, divisor, stride, indexSin),
	Cos(GL_FLOAT, sizeof(float) * 3, 3, divisor, stride, indexCos)
{ }



void AttribAngle3D::Bind(const unsigned char * & offset) const
{
	Sin.Bind(offset);
	Cos.Bind(offset);
}
