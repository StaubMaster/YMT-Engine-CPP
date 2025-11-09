
#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

namespace Shader
{
	class Base;
};

namespace Multiform
{
	class Base;
};

namespace Uniform
{
class Base
{
	public:
		std::string Name;
		Shader::Base & Shader;
		Multiform::Base * Uniform;
		bool Changed;

		/*
			name and shader go down the Constructor chain until here
			put them both into one container called UniformData or something
			so only one thing needs to be passed down instead of 2 ?
		*/
	protected:
		Base(std::string name, Shader::Base & shader);
		virtual ~Base();

	public:
		void PutData();
};
};

#endif
