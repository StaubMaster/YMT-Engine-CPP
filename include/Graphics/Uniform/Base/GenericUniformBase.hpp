
#ifndef  GENERIC_UNIFORM_BASE_HPP
# define GENERIC_UNIFORM_BASE_HPP

# include "Graphics/Uniform/Base/UniformBase.hpp"

class BaseShader;

namespace Uniform
{
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
};

#endif
