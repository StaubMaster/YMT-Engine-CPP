
#ifndef  ATTRIB_TRANS_3D_HPP
# define ATTRIB_TRANS_3D_HPP

# include "AttributeLocation.hpp"
# include "AttributeBase.hpp"

# include "AttribPoint3D.hpp"
# include "AttribAngle3D.hpp"

namespace Attribute
{
class Trans3D : public Attribute::Base
{
	private:
		Attribute::Point3D Pos;
		Attribute::Angle3D Rot;

	public:
		Trans3D(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos,
			unsigned int indexRotSin,
			unsigned int indexRotCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
