#include "Graphics/Texture/Base.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Texture::Base::Base(unsigned int type)
{
	Type = type;
	glGenTextures(1, &GL_Texture);
	glBindTexture(Type, GL_Texture);
	Debug::Log << "++++ Texture::Base" << Debug::Done;
}
Texture::Base::~Base()
{
	Debug::Log << "---- Texture::Base" << Debug::Done;
	glDeleteTextures(1, &GL_Texture);
}



void Texture::Base::Bind()
{
	glBindTexture(Type, GL_Texture);
}
