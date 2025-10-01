
#ifndef  ATTRIB_ANGLE_3D_HPP
# define ATTRIB_ANGLE_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

namespace Attribute
{
class Angle3D : public Attribute::Base
{
	private:
		Attribute::Location Sin;
		Attribute::Location Cos;

	public:
		Angle3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexSin,
			unsigned int indexCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
