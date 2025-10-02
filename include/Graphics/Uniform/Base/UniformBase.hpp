
#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

class BaseShader;

namespace Multiform
{
	class MultiformBase;
};

namespace Uniform
{
class UniformBase
{
	public:
		std::string Name;
		BaseShader & Shader;
		Multiform::MultiformBase * Uniform;
		bool Changed;

	protected:
		UniformBase(std::string name, BaseShader & shader);
		virtual ~UniformBase();

	public:
		void PutData();
};
};

#endif
