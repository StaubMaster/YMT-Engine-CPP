
#ifndef  SIMPLE_3D_INST_ATTRIB_HPP
# define SIMPLE_3D_INST_ATTRIB_HPP

# include "Graphics/Attribute/AttributeBase.hpp"

# include "Graphics/Attribute/AttribTrans3D.hpp"

class Simple3D_InstAttrib : public AttributeBase
{
	private:
		AttribTrans3D	Trans;

	public:
		Simple3D_InstAttrib(
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
