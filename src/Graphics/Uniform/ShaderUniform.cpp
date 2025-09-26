
#include "Graphics/Uniform/ShaderUniform.hpp"

ShaderUniform::ShaderUniform(std::string name, BaseShader & shader) :
	Shader(shader)
{
	Name = name;
	Uniform = NULL;
	Changed = false;
	shader.Uniforms.push_back(this);
}
ShaderUniform::~ShaderUniform()
{
	
}


void ShaderUniform::PutData()
{
	Uniform -> Data_PutUniform(this);
}
