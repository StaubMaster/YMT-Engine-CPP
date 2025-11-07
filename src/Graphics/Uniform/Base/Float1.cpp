#include "Graphics/Uniform/Base/Float1.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "OpenGL/openGL.h"



Uniform::Float1::Float1(std::string name, BaseShader & shader) : FloatN(1, name, shader)
{ }
Uniform::Float1::Float1(int count, std::string name, BaseShader & shader) : FloatN(count, name, shader)
{ }



void Uniform::Float1::PutData(const float * val)
{
	glUniform1fv(Location, Count, val);
}
