#include "Physics3D/Physics3D_InstAttrib.hpp"



Physics3D_InstAttrib::Physics3D_InstAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexTransPos,
	unsigned int indexTransRotSin,
	unsigned int indexTransRotCos,
	unsigned int indexVelPos,
	unsigned int indexVelRotSin,
	unsigned int indexVelRotCos
) :
	Trans(divisor, stride, indexTransPos, indexTransRotSin, indexTransRotCos),
	Vel(divisor, stride, indexVelPos, indexVelRotSin, indexVelRotCos)
{ }



void Physics3D_InstAttrib::Bind(const unsigned char * & offset) const
{
	Trans.Bind(offset);
	Vel.Bind(offset);
}
