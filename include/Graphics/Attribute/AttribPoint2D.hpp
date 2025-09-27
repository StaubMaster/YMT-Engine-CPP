
#ifndef  ATTRIB_POINT_2D_HPP
# define ATTRIB_POINT_2D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

class AttribPoint2D : public AttributeBase
{
	private:
		AttributeLocation Pos;

	public:
		AttribPoint2D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
