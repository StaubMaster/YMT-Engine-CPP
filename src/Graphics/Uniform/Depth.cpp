#include "Graphics/Uniform/Depth.hpp"
#include "DataStruct/Depth.hpp"



Uniform::Depth::Depth(std::string name, Shader::Base & shader) : GBase(name, shader),
	Factors(name + ".Factors", shader),
	Range(name + ".Range", shader),
	Color(name + ".Color", shader)
{
	
}

void Uniform::Depth::PutData(::Depth val)
{
	Factors.PutData(val.Factors);
	Range.PutData(val.Range);
	Color.PutData(val.Color);
}
