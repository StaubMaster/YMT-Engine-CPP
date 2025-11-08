#include "Texture/TextureBase.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



TextureBase::TextureBase(unsigned int type)
{
	Type = type;
	glGenTextures(1, &GL_Texture);
	glBindTexture(Type, GL_Texture);
	Debug::Log << "++++ TextureBase" << Debug::Done;
}
TextureBase::~TextureBase()
{
	Debug::Log << "---- TextureBase" << Debug::Done;
	glDeleteTextures(1, &GL_Texture);
}



void TextureBase::Bind()
{
	glBindTexture(Type, GL_Texture);
}
