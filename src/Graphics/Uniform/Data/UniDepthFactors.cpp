#include "Graphics/Uniform/Data/1D/UniDepthFactors.hpp"
#include "DataStruct/DepthFactors.hpp"

#include "OpenGL/openGL.h"



Uniform::DepthFactors::DepthFactors(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
	//std::cout << "UniDepthFactors.Location: " << Location << "\n";
}

void Uniform::DepthFactors::PutData(::DepthFactors df)
{
	glUniform1fv(Location, 7, (float*)(&df));
}
