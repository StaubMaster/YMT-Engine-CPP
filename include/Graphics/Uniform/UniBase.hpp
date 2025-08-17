#ifndef UNI_BASE_HPP
# define UNI_BASE_HPP

# include "../BaseShader.hpp"

class UniBase
{
	protected:
		const BaseShader * Program;
		int Location;

	protected:
		UniBase(const BaseShader * program, const std::string & name);
		virtual ~UniBase();

	public:
		virtual void Update() = 0;
};

#endif