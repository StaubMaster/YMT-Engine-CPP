#include "Graphics/Uniform/Data/DepthFactors.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/DepthFactors.hpp"
#include "OpenGL/openGL.h"



Uniform::DepthFactors::DepthFactors(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::DepthFactors::PutData(::DepthFactors df)
{
	glUniform1fv(Location, 7, (float*)(&df));
}
