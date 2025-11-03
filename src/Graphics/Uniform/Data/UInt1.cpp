#include "Graphics/Uniform/Data/UInt1.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "OpenGL/openGL.h"



Uniform::UInt1::UInt1(int count, std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Count(count),
	Location(shader.UniformFind(name))
{

}

void Uniform::UInt1::PutData(unsigned int * val)
{
	glUniform1uiv(Location, Count, val);
}
