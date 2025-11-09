#include "Graphics/Uniform/Base/Base.hpp"
#include "Graphics/Multiform/Base/Base.hpp"
#include "Graphics/Shader/Base.hpp"



Uniform::Base::Base(std::string name, Shader::Base & shader) :
	Shader(shader)
{
	Name = name;
	Uniform = NULL;
	Changed = false;
	shader.Uniforms.push_back(this);
}
Uniform::Base::~Base()
{
	
}



void Uniform::Base::PutData()
{
	Uniform -> Data_PutUniform(this);
}
