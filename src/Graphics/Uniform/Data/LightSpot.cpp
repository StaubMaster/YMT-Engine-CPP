#include "Graphics/Uniform/Data/LightSpot.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/LightSpot.hpp"
#include "OpenGL/openGL.h"



Uniform::LightSpot::LightSpot(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Base(name + ".Base", shader),
	Pos(name + ".Position", shader),
	Dir(name + ".Direction", shader),
	Range(name + ".Range", shader)
{

}

void Uniform::LightSpot::PutData(::LightSpot val)
{
	Base.PutData(val.Base);
	Pos.PutData(val.Pos);
	Dir.PutData(val.Dir);
	Range.PutData(val.Range);
}
