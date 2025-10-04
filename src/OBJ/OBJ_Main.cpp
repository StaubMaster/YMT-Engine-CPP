#include "OBJ/OBJ_Main.hpp"

#include "OpenGL/openGL.h"



OBJ_MainAttrib::OBJ_MainAttrib(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor,
	unsigned int indexAmbientColor,
	unsigned int indexDiffuseColor,
	unsigned int indexSpecularPower,
	unsigned int indexSpecularColor
) :
	Position(divisor, stride, indexPosition),
	Texture(divisor, stride, indexTexture),
	Normal(divisor, stride, indexNormal),
	Color(divisor, stride, indexColor),
	AmbientColor(divisor, stride, indexAmbientColor),
	DiffuseColor(divisor, stride, indexDiffuseColor),
	SpecularPower(divisor, stride, indexSpecularPower),
	SpecularColor(divisor, stride, indexSpecularColor)
{ }

void OBJ_MainAttrib::Bind(const unsigned char * & offset) const
{
	Position.Bind(offset);
	Texture.Bind(offset);
	Normal.Bind(offset);
	Color.Bind(offset);

	AmbientColor.Bind(offset);
	DiffuseColor.Bind(offset);
	SpecularPower.Bind(offset);
	SpecularColor.Bind(offset);
}



OBJ_MainBuffer::OBJ_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexTexture,
	unsigned int indexNormal,
	unsigned int indexColor,
	unsigned int indexAmbientColor,
	unsigned int indexDiffuseColor,
	unsigned int indexSpecularPower,
	unsigned int indexSpecularColor
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new OBJ_MainAttrib(0, sizeof(OBJ_MainData), indexPosition, indexTexture, indexNormal, indexColor,
		indexAmbientColor, indexDiffuseColor, indexSpecularPower, indexSpecularColor)
	}) { }
OBJ_MainBuffer::~OBJ_MainBuffer() {}
