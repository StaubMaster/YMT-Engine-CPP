#include "Graphics/Uniform/LightSolar.hpp"
#include "DataStruct/LightSolar.hpp"



Uniform::LightSolar::LightSolar(std::string name, Shader::Base & shader) : GBase(name, shader),
	Base(name + ".Base", shader),
	Dir(name + ".Direction", shader)
{ }

void Uniform::LightSolar::PutData(::LightSolar val)
{
	Base.PutData(val.Base);
	Dir.PutData(val.Dir);
}
