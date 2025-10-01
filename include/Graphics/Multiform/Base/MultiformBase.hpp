
#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

#include <string>

class BaseShader;
namespace Uniform
{
	class UniformBase;
};

class MultiformBase
{
	public:
		std::string Name;

	protected:
		MultiformBase(std::string name);
		~MultiformBase();

	public:
		virtual void FindUniforms(BaseShader ** shaders, int len) = 0;
		virtual void Data_PutUniform(Uniform::UniformBase * uni_base) = 0;
};

#endif
