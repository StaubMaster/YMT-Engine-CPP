#include "Graphics/Uniform/Base/UniformBase.hpp"
#include "Graphics/Uniform/Base/MultiformBase.hpp"
#include "Graphics/Shader/BaseShader.hpp"



UniformBase::UniformBase(std::string name, BaseShader & shader) :
	Shader(shader)
{
	Name = name;
	Uniform = NULL;
	Changed = false;
	shader.Uniforms.push_back(this);
}
UniformBase::~UniformBase()
{
	
}



void UniformBase::PutData()
{
	Uniform -> Data_PutUniform(this);
}
