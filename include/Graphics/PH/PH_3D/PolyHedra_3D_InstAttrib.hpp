
#ifndef  POLYHEDRA_3D_INST_ATTRIB_HPP
# define POLYHEDRA_3D_INST_ATTRIB_HPP

# include "Graphics/Attribute/AttributeLocation.hpp"
# include "Graphics/Attribute/AttributeBase.hpp"

# include "Graphics/Attribute/AttribTrans3D.hpp"

class PolyHedra_3D_InstAttrib : public AttributeBase
{
	private:
		AttribTrans3D	Trans;

	public:
		PolyHedra_3D_InstAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexTransPos,
			unsigned int indexTransRotSin,
			unsigned int indexTransRotCos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
