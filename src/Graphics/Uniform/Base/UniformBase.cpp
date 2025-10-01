#include "Graphics/Uniform/Base/UniformBase.hpp"
#include "Graphics/Multiform/Base/MultiformBase.hpp"
#include "Graphics/Shader/BaseShader.hpp"



Uniform::UniformBase::UniformBase(std::string name, BaseShader & shader) :
	Shader(shader)
{
	Name = name;
	Uniform = NULL;
	Changed = false;
	shader.Uniforms.push_back(this);
}
Uniform::UniformBase::~UniformBase()
{
	
}



void Uniform::UniformBase::PutData()
{
	Uniform -> Data_PutUniform(this);
}
