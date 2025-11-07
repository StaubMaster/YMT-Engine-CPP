#include "Graphics/Uniform/Data/LightBase.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/LightBase.hpp"
#include "OpenGL/openGL.h"



Uniform::LightBase::LightBase(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Intensity(name + ".Intensity", shader),
	Color(name + ".Color", shader)
{ }

void Uniform::LightBase::PutData(::LightBase val)
{
	Intensity.PutData(&val.Intensity);
	Color.PutData(val.Color);
}
