#include "Graphics/Uniform/Data/DepthFactors.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/DepthFactors.hpp"
#include "OpenGL/openGL.h"



Uniform::DepthFactors::DepthFactors(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Location(7, name, shader)
{ }

void Uniform::DepthFactors::PutData(::DepthFactors val)
{
	Location.PutVoid(&val);
}
