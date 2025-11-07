#include "Graphics/Uniform/Data/Color.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/Color.hpp"
#include "OpenGL/openGL.h"



Uniform::Color::Color(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Location(name, shader)
{ }

void Uniform::Color::PutData(::Color val)
{
	Location.PutVoid(&val);
}
