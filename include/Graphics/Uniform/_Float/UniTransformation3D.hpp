#ifndef UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

# include "UniFloat3.hpp"
# include "../../../Abstract3D/Transformation3D.hpp"

class UniTransformation3D : public UniFloat3
{
	public:
		UniTransformation3D(const BaseShader * program, const std::string & name);
		~UniTransformation3D();

	public:
		void Value(const Transformation3D & trans);
};

#endif