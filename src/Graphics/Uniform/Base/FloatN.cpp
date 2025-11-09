#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::FloatN::FloatN(int count, std::string name, Shader::Base & shader) : GBase(name, shader),
	Location(shader.UniformFind(name)),
	Count(count)
{ }



void Uniform::FloatN::PutVoid(const void * val)
{
	PutData((const float *)val);
}
