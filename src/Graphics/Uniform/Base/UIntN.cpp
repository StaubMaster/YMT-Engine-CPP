#include "Graphics/Uniform/Base/UIntN.hpp"
#include "Graphics/Shader/BaseShader.hpp"



Uniform::UIntN::UIntN(int count, std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Location(shader.UniformFind(name)),
	Count(count)
{ }



void Uniform::UIntN::PutVoid(const void * val)
{
	PutData((const unsigned int *)val);
}
