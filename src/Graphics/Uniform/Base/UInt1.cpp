#include "Graphics/Uniform/Base/UInt1.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "OpenGL/openGL.h"



Uniform::UInt1::UInt1(std::string name, BaseShader & shader) : UIntN(1, name, shader)
{ }
Uniform::UInt1::UInt1(int count, std::string name, BaseShader & shader) : UIntN(count, name, shader)
{ }



void Uniform::UInt1::PutData(const unsigned int * val)
{
	glUniform1uiv(Location, Count, val);
}
