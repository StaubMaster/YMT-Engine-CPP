#include "Graphics/Uniform/Base/Float3.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "OpenGL/openGL.h"



Uniform::Float3::Float3(std::string name, BaseShader & shader) : FloatN(1, name, shader)
{ }
Uniform::Float3::Float3(int count, std::string name, BaseShader & shader) : FloatN(count, name, shader)
{ }



void Uniform::Float3::PutData(const float * val)
{
	glUniform3fv(Location, 1, val);
}
