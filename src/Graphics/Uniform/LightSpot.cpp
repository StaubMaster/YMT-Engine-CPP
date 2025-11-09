#include "Graphics/Uniform/LightSpot.hpp"
#include "DataStruct/LightSpot.hpp"



Uniform::LightSpot::LightSpot(std::string name, Shader::Base & shader) : GBase(name, shader),
	Base(name + ".Base", shader),
	Pos(name + ".Position", shader),
	Dir(name + ".Direction", shader),
	Range(name + ".Range", shader)
{ }

void Uniform::LightSpot::PutData(::LightSpot val)
{
	Base.PutData(val.Base);
	Pos.PutData(val.Pos);
	Dir.PutData(val.Dir);
	Range.PutData(val.Range);
}
