#include "PH/PolyHedra_MainAttrib.hpp"

#include "OpenGL/openGL.h"



PolyHedra_MainAttrib::PolyHedra_MainAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPosition,
	unsigned int indexNormal,
	unsigned int indexTexture
) :
	Position(divisor, stride, indexPosition),
	Normal(divisor, stride, indexNormal),
	Texture(divisor, stride, indexTexture)
{ }



void PolyHedra_MainAttrib::Bind(const unsigned char * & offset) const
{
	Position.Bind(offset);
	Normal.Bind(offset);
	Texture.Bind(offset);
}
