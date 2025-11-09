
#ifndef  POLYHEDRA_MAIN_ATTRIB_HPP
# define POLYHEDRA_MAIN_ATTRIB_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Graphics/Attribute/Point3D.hpp"
# include "Graphics/Attribute/Point2D.hpp"

class PolyHedra_MainAttrib : public Attribute::Base
{
	private:
		Attribute::Point3D	Position;
		Attribute::Point3D	Normal;
		Attribute::Point2D	Texture;

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
