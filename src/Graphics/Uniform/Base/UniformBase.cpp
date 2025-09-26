
#include "Graphics/Uniform/Base/UniformBase.hpp"

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
