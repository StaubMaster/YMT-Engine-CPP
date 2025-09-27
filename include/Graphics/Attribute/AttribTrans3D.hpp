
#ifndef  ATTRIB_TRANS_3D_HPP
# define ATTRIB_TRANS_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

# include "AttribPoint3D.hpp"
# include "AttribAngle3D.hpp"

class AttribTrans3D : public AttributeBase
{
	private:
		AttribPoint3D Pos;
		AttribAngle3D Rot;

	public:
		AttribTrans3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos,
			unsigned int indexRotSin,
			unsigned int indexRotCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
