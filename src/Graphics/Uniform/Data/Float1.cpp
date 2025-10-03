#include "Graphics/Uniform/Data/Float1.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "OpenGL/openGL.h"



Uniform::Float1::Float1(int count, std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Count(count),
	Location(shader.UniformFind(name))
{

}

void Uniform::Float1::PutData(float * val)
{
	glUniform1fv(Location, Count, val);
}
