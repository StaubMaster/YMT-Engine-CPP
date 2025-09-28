
#ifndef  POLYHEDRA_MAIN_ATTRIB_HPP
# define POLYHEDRA_MAIN_ATTRIB_HPP

# include "Graphics/Attribute/AttributeLocation.hpp"
# include "Graphics/Attribute/AttributeBase.hpp"

# include "Graphics/Attribute/AttribPoint3D.hpp"
# include "Graphics/Attribute/AttribPoint2D.hpp"

class PolyHedra_MainAttrib : public AttributeBase
{
	private:
		AttribPoint3D	Position;
		AttribPoint3D	Normal;
		AttribPoint2D	Texture;

	public:
		PolyHedra_MainAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPosition,
			unsigned int indexNormal,
			unsigned int indexTexture
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
