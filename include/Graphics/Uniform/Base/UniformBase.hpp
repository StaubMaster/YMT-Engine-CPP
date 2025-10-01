
#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <string>

class BaseShader;
class MultiformBase;

class UniformBase
{
	public:
		std::string Name;
		BaseShader & Shader;
		MultiformBase * Uniform;
		bool Changed;

	protected:
		UniformBase(std::string name, BaseShader & shader);
		virtual ~UniformBase();

	public:
		void PutData();
};

#endif
