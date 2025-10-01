
#ifndef  ATTRIB_POINT_4D_HPP
# define ATTRIB_POINT_4D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

namespace Attribute
{
class Point4D : public Attribute::Base
{
	private:
		Attribute::Location Pos;

	public:
		Point4D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
