#include "OBJ/OBJ_Main.hpp"

#include "OpenGL/openGL.h"



OBJ_MainAttrib::OBJ_MainAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor
) :
	Position(divisor, stride, indexPosition),
	Texture(divisor, stride, indexTexture),
	Normal(divisor, stride, indexNormal),
	Color(divisor, stride, indexColor)
{ }

void OBJ_MainAttrib::Bind(const unsigned char * & offset) const
{
	Position.Bind(offset);
	Texture.Bind(offset);
	Normal.Bind(offset);
	Color.Bind(offset);
}



OBJ_MainBuffer::OBJ_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new OBJ_MainAttrib(0, sizeof(OBJ_MainData), indexPosition, indexTexture, indexNormal, indexColor)
	}) { }
OBJ_MainBuffer::~OBJ_MainBuffer() {}
