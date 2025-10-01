
#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

namespace Attribute
{
class Point2D : public Attribute::Base
{
	private:
		Attribute::Location Pos;

	public:
		Point2D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
