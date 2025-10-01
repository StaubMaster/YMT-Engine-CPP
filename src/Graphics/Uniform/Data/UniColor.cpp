#include "Graphics/Uniform/Data/UniColor.hpp"
#include "DataStruct/Color.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



Uniform::Color::Color(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::Color::PutData(::Color val)
{
	glUniform3fv(Location, 1, (float*)(&val));
}
