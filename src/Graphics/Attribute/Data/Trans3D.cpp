#include "Graphics/Attribute/Data/Trans3D.hpp"
#include "OpenGL/openGL.h"



Attribute::Trans3D::Trans3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos,
	unsigned int indexRotSin,
	unsigned int indexRotCos
) :
	Pos(divisor, stride, indexPos),
	Rot(divisor, stride, indexRotSin, indexRotCos)
{ }



void Attribute::Trans3D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
	Rot.Bind(offset);
}
