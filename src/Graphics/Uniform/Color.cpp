#include "Graphics/Uniform/Color.hpp"
#include "DataStruct/Color.hpp"



Uniform::Color::Color(std::string name, Shader::Base & shader) : GBase(name, shader),
	Location(name, shader)
{ }

void Uniform::Color::PutData(::Color val)
{
	Location.PutVoid(&val);
}
