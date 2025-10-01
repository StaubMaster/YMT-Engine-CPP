#include "Graphics/Uniform/Data/1D/UniDepthFactors.hpp"
#include "Data/1D/DepthFactors.hpp"

#include "OpenGL/openGL.h"



UniDepthFactors::UniDepthFactors(std::string name, BaseShader & shader) :
	GenericUniformBase<DepthFactors>(name, shader)
{
	Location = shader.UniformFind(name);
	//std::cout << "UniDepthFactors.Location: " << Location << "\n";
}

void UniDepthFactors::PutData(DepthFactors df)
{
	glUniform1fv(Location, 7, (float*)(&df));
}







MultiDepthFactors::MultiDepthFactors(std::string name) :
	GenericMultiformBase<UniDepthFactors, DepthFactors>(name)
{
	
}
