
#ifndef  PHYSICS_3D_INST_ATTRIB_HPP
# define PHYSICS_3D_INST_ATTRIB_HPP

# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Data/Trans3D.hpp"

class Physics3D_InstAttrib : public Attribute::Base
{
	private:
		Attribute::Trans3D	Trans;
		Attribute::Trans3D	Vel;

	public:
		Physics3D_InstAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexTransPos,
			unsigned int indexTransRotSin,
			unsigned int indexTransRotCos,
			unsigned int indexVelPos,
			unsigned int indexVelRotSin,
			unsigned int indexVelRotCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
