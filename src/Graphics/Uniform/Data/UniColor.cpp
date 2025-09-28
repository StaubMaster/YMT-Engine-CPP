#include "Graphics/Uniform/Data/UniColor.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



UniColor::UniColor(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void UniColor::PutData(Color val)
{
	glUniform3fv(Location, 1, (float*)(&val));
}







MultiColor::MultiColor(std::string name) : GenericMultiformBase(name)
{

}
