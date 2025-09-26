
#ifndef UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <iostream>
# include "OpenGL/openGL.h"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/ShaderUniform.hpp"

class BaseShader;
class ShaderUniform;

class UniformBase
{
	public:
		std::string Name;

	protected:
		UniformBase(std::string name);
		~UniformBase();

	public:
		virtual void FindUniforms(BaseShader ** shaders, int len) = 0;
		virtual void Data_PutUniform(ShaderUniform * uni_base) = 0;
};

#endif
