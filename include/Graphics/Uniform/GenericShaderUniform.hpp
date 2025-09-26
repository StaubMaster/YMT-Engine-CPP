
#ifndef GENERIC_SHADER_UNIFORM_HPP
# define GENERIC_SHADER_UNIFORM_HPP

# include <iostream>
# include "OpenGL/openGL.h"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/UniformBase.hpp"
# include "Graphics/Uniform/ShaderUniform.hpp"

class BaseShader;
class UniformBase;

template <typename DataType>
class GenericShaderUniform : public ShaderUniform
{
	protected:
		GenericShaderUniform(std::string name, BaseShader & shader) :
			ShaderUniform(name, shader) { }
		virtual ~GenericShaderUniform() { }

	public:
		virtual void PutData(DataType data) = 0;
};

#endif
