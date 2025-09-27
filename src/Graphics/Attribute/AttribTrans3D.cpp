#include "Graphics/Attribute/AttribTrans3D.hpp"
#include "OpenGL/openGL.h"
#include "Abstract.hpp"



AttribTrans3D::AttribTrans3D(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos,
	unsigned int indexRotSin,
	unsigned int indexRotCos
) :
	Pos(divisor, stride, indexPos),
	Rot(divisor, stride, indexRotSin, indexRotCos)
{ }



void AttribTrans3D::Bind(const unsigned char * & offset) const
{
	Pos.Bind(offset);
	Rot.Bind(offset);
}
