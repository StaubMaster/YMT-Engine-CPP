#include "DataStruct/Inst/Simple3D/Simple3D_InstAttrib.hpp"



Simple3D_InstAttrib::Simple3D_InstAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexTransPos,
	unsigned int indexTransRot
) :
	Trans(divisor, stride, indexTransPos, indexTransRot)
{ }



void Simple3D_InstAttrib::Bind(const unsigned char * & offset) const
{
	Trans.Bind(offset);
}
