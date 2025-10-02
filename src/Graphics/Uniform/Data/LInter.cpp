#include "Graphics/Uniform/Data/LInter.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/LInter.hpp"
#include "OpenGL/openGL.h"

#include <iostream>



Uniform::LInter::LInter(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	LocationT0 = shader.UniformFind(name + ".T0");
	LocationT1 = shader.UniformFind(name + ".T1");
}

void Uniform::LInter::PutData(::LInter val)
{
	glUniform1fv(LocationT0, 1, ((float*)(&val) + 0));
	glUniform1fv(LocationT1, 1, ((float*)(&val) + 1));
}
