#include "TextureBase.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



TextureBase::TextureBase(unsigned int type)
{
	Type = type;
	glGenTextures(1, &GL_Texture);
	glBindTexture(Type, GL_Texture);
}
TextureBase::~TextureBase()
{
	glDeleteTextures(1, &GL_Texture);
}



void TextureBase::Bind()
{
	glBindTexture(Type, GL_Texture);
}
