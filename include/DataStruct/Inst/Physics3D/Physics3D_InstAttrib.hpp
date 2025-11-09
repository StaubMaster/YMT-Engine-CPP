
#ifndef  PHYSICS_3D_INST_ATTRIB_HPP
# define PHYSICS_3D_INST_ATTRIB_HPP

# include "Graphics/Attribute/Base/AttributeBase.hpp"
# include "Graphics/Attribute/Trans3D.hpp"

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
			unsigned int indexTransRot,
			unsigned int indexVelPos,
			unsigned int indexVelRot
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
