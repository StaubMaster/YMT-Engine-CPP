#include "Graphics/Uniform/Base/UInt1.hpp"
#include "OpenGL/openGL.h"



Uniform::UInt1::UInt1(std::string name, Shader::Base & shader) : UIntN(1, name, shader)
{ }
Uniform::UInt1::UInt1(int count, std::string name, Shader::Base & shader) : UIntN(count, name, shader)
{ }



void Uniform::UInt1::PutData(const unsigned int * val)
{
	glUniform1uiv(Location, Count, val);
}
