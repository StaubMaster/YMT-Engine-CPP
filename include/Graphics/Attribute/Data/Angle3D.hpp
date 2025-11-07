
#ifndef  ATTRIB_ANGLE_3D_HPP
# define ATTRIB_ANGLE_3D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Angle3D : public Attribute::Base
{
	private:
		Attribute::FloatN Location0;
		Attribute::FloatN Location1;
		Attribute::FloatN Location2;

	public:
		Angle3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int index
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
