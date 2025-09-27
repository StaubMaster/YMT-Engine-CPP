
#ifndef  ATTRIB_POINT_3D_HPP
# define ATTRIB_POINT_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

class AttribPoint3D : public AttributeBase
{
	private:
		AttributeLocation Pos;

	public:
		AttribPoint3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
