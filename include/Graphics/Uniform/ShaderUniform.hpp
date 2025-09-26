
#ifndef SHADER_UNIFORM_HPP
# define SHADER_UNIFORM_HPP

# include <iostream>
# include "OpenGL/openGL.h"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/UniformBase.hpp"

class BaseShader;
class UniformBase;

class ShaderUniform
{
	public:
		std::string Name;
		BaseShader & Shader;
		UniformBase * Uniform;
		bool Changed;

	protected:
		ShaderUniform(std::string name, BaseShader & shader);
		virtual ~ShaderUniform();

	public:
		void PutData();
};

#endif
