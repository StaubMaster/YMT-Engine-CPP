#include "OBJ/OBJ_Main.hpp"

#include "Abstract.hpp"

#include "OpenGL/openGL.h"



OBJ_MainAttrib::OBJ_MainAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal
) :
	Position(divisor, stride, indexPosition),
	Texture(divisor, stride, indexTexture),
	Normal(divisor, stride, indexNormal)
{ }

void OBJ_MainAttrib::Bind(const unsigned char * & offset) const
{
	Position.Bind(offset);
	Texture.Bind(offset);
	Normal.Bind(offset);
}



OBJ_MainBuffer::OBJ_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal
) :
	BaseBuffer(1, (AttributeBase * []) {
		new OBJ_MainAttrib(0, sizeof(OBJ_MainData), indexPosition, indexTexture, indexNormal)
	}) { }
OBJ_MainBuffer::~OBJ_MainBuffer() {}
