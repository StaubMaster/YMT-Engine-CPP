#ifndef UNI_FLOAT_2_HPP
# define UNI_FLOAT_2_HPP

# include "UniFloatN.hpp"

class UniFloat2 : public UniFloatN
{
	protected:
		UniFloat2(const BaseShader * program, const std::string & name, int count);
		virtual ~UniFloat2();

	public:
		void Set(const float * data);
};

#endif