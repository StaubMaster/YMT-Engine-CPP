
#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Base/FloatN.hpp"

namespace Attribute
{
class Point2D : public Attribute::Base
{
	private:
		Attribute::FloatN Pos;

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
