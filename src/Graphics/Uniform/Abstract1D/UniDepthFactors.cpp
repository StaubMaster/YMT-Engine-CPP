
#include "Graphics/Uniform/Abstract1D/UniDepthFactors.hpp"
#include "OpenGL/openGL.h"
#include <iostream>

UniDepthFactors::UniDepthFactors(std::string name, BaseShader & shader) :
	GenericShaderUniform<DepthFactors>(name, shader)
{
	Location = shader.UniformFind(name);
	//std::cout << "UniDepthFactors.Location: " << Location << "\n";
}

void UniDepthFactors::PutData(DepthFactors df)
{
	glUniform1fv(Location, 7, (float*)(&df));
}







MultiDepthFactors::MultiDepthFactors(std::string name) :
	GenericUniformBase<UniDepthFactors, DepthFactors>(name)
{
	
}
