
#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

#include <string>

namespace Shader
{
	class Base;
};

namespace Uniform
{
	class Base;
};

namespace Multiform
{
class Base
{
	public:
		std::string Name;

	protected:
		Base(std::string name);
		~Base();

	public:
		virtual void FindUniforms(Shader::Base ** shaders, int len) = 0;
		virtual void Data_PutUniform(Uniform::Base * uni_base) = 0;
};
};

#endif
