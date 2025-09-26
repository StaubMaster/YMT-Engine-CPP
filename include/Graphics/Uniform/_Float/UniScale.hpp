#ifndef UNI_SCALE_HPP
# define UNI_SCALE_HPP

#include "UniFloat2.hpp"

class UniScale : public UniFloat2
{
	public:
		UniScale(const BaseShader * program, const std::string & name);
		~UniScale();

	public:
		void Value(float w, float h);
};

#endif