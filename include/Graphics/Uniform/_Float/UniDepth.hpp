#ifndef UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

#include "UniFloat1.hpp"

class UniDepth : public UniFloat1
{
	public:
		UniDepth(const BaseShader * program, const std::string & name);
		~UniDepth();

	public:
		void Value(float near, float far);
};

#endif