
#ifndef  ATTRIB_POINT_4D_HPP
# define ATTRIB_POINT_4D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

class AttribPoint4D : public AttributeBase
{
	private:
		AttributeLocation Pos;

	public:
		AttribPoint4D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
