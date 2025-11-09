#include "Graphics/Uniform/Base/Float2.hpp"
#include "OpenGL/openGL.h"



Uniform::Float2::Float2(std::string name, Shader::Base & shader) : FloatN(1, name, shader)
{ }
Uniform::Float2::Float2(int count, std::string name, Shader::Base & shader) : FloatN(count, name, shader)
{ }



void Uniform::Float2::PutData(const float * val)
{
	glUniform2fv(Location, Count, val);
}
