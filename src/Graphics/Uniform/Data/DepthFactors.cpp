#include "Graphics/Uniform/Data/DepthFactors.hpp"
#include "DataStruct/DepthFactors.hpp"



Uniform::DepthFactors::DepthFactors(std::string name, Shader::Base & shader) : GBase(name, shader),
	Location(7, name, shader)
{ }

void Uniform::DepthFactors::PutData(::DepthFactors val)
{
	Location.PutVoid(&val);
}
