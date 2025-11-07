#include "Graphics/Uniform/Base/FloatN.hpp"
#include "Graphics/Shader/BaseShader.hpp"



Uniform::FloatN::FloatN(int count, std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Location(shader.UniformFind(name)),
	Count(count)
{ }



void Uniform::FloatN::PutVoid(const void * val)
{
	PutData((const float *)val);
}
