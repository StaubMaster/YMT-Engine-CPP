
#ifndef  ATTRIB_ANGLE_3D_HPP
# define ATTRIB_ANGLE_3D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

namespace Attribute
{
class Angle3D : public Attribute::Base
{
	private:
		Attribute::Location Location0;
		Attribute::Location Location1;
		Attribute::Location Location2;

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
