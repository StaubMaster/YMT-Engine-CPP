
#ifndef  ATTRIB_ANGLE_3D_HPP
# define ATTRIB_ANGLE_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

class AttribAngle3D : public AttributeBase
{
	private:
		AttributeLocation Sin;
		AttributeLocation Cos;

	public:
		AttribAngle3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexSin,
			unsigned int indexCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
