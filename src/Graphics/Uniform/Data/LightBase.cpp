#include "Graphics/Uniform/Data/LightBase.hpp"
#include "DataStruct/LightBase.hpp"



Uniform::LightBase::LightBase(std::string name, Shader::Base & shader) : GBase(name, shader),
	Intensity(name + ".Intensity", shader),
	Color(name + ".Color", shader)
{ }

void Uniform::LightBase::PutData(::LightBase val)
{
	Intensity.PutData(&val.Intensity);
	Color.PutData(val.Color);
}
