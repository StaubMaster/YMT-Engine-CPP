
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

		/*
			name and shader go down the Constructor chain until here
			put them both into one container called UniformData or something
			so only one thing needs to be passed down instead of 2 ?
		*/
	protected:
		UniformBase(std::string name, BaseShader & shader);
		virtual ~UniformBase();

	public:
		void PutData();
};
};

#endif
