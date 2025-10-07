#include "Physics3D/Physics3D_InstAttrib.hpp"



Physics3D_InstAttrib::Physics3D_InstAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexTransPos,
	unsigned int indexTransRot,
	unsigned int indexVelPos,
	unsigned int indexVelRot
) :
	Trans(divisor, stride, indexTransPos, indexTransRot),
	Vel(divisor, stride, indexVelPos, indexVelRot)
{ }



void Physics3D_InstAttrib::Bind(const unsigned char * & offset) const
{
	Trans.Bind(offset);
	Vel.Bind(offset);
}
