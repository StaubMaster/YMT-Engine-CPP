#ifndef UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "UniFloatN.hpp"

class UniFloat1 : public UniFloatN
{
	protected:
		UniFloat1(const BaseShader * program, const std::string & name, int count);
		virtual ~UniFloat1();

	public:
		void Set(const float * data);
};

#endif