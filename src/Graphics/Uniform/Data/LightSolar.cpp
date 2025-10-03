#include "Graphics/Uniform/Data/LightSolar.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/LightSolar.hpp"
#include "OpenGL/openGL.h"



Uniform::LightSolar::LightSolar(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Base(name + ".Base", shader),
	Dir(name + ".Direction", shader)
{

}

void Uniform::LightSolar::PutData(::LightSolar val)
{
	Base.PutData(val.Base);
	Dir.PutData(val.Dir);
}
