
#ifndef  ATTRIB_POINT_3D_HPP
# define ATTRIB_POINT_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

namespace Attribute
{
class Point3D : public Attribute::Base
{
	private:
		Attribute::Location Pos;

	public:
		Point3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
