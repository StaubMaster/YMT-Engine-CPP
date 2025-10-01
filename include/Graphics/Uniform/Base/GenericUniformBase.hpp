
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

//# include "Graphics/Shader/BaseShader.hpp"
//# include "Graphics/Uniform/Base/MultiformBase.hpp"
# include "Graphics/Uniform/Base/UniformBase.hpp"
//# include "OpenGL/openGL.h"
//# include <iostream>

class BaseShader;
//class UniformBase;
class MultiformBase;

template <typename DataType>
class GenericUniformBase : public UniformBase
{
	protected:
		GenericUniformBase(std::string name, BaseShader & shader) :
			UniformBase(name, shader) { }
		virtual ~GenericUniformBase() { }

	public:
		virtual void PutData(DataType data) = 0;
};

#endif
