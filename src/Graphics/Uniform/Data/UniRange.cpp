#include "Graphics/Uniform/Data/1D/UniRange.hpp"
#include "DataStruct/Range.hpp"

#include "OpenGL/openGL.h"



Uniform::Range::Range(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	LocationMin = shader.UniformFind(name + ".Min");
	LocationLen = shader.UniformFind(name + ".Len");
	LocationMax = shader.UniformFind(name + ".Max");
}

void Uniform::Range::PutData(::Range val)
{
	glUniform1fv(LocationMin, 1, (float*)(&val.Min));
	glUniform1fv(LocationLen, 1, (float*)(&val.Len));
	glUniform1fv(LocationMax, 1, (float*)(&val.Max));
}
