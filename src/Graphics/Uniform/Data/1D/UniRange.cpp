#include "Graphics/Uniform/Data/1D/UniRange.hpp"
#include "Data/1D/Range.hpp"

#include "OpenGL/openGL.h"



UniRange::UniRange(std::string name, BaseShader & shader) :
	GenericUniformBase(name, shader)
{
	LocationMin = shader.UniformFind(name + ".Min");
	LocationLen = shader.UniformFind(name + ".Len");
	LocationMax = shader.UniformFind(name + ".Max");
}

void UniRange::PutData(Range val)
{
	glUniform1fv(LocationMin, 1, (float*)(&val.Min));
	glUniform1fv(LocationLen, 1, (float*)(&val.Len));
	glUniform1fv(LocationMax, 1, (float*)(&val.Max));
}







MultiRange::MultiRange(std::string name) :
	GenericMultiformBase(name)
{

}
