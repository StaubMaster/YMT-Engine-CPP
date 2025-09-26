#ifndef UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "UniFloatN.hpp"

class UniFloat3 : public UniFloatN
{
	protected:
		UniFloat3(const BaseShader * program, const std::string & name, int count);
		virtual ~UniFloat3();

	public:
		void Set(const float * data);
};

#endif