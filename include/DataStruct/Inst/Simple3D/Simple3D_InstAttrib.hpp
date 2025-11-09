
#ifndef  SIMPLE_3D_INST_ATTRIB_HPP
# define SIMPLE_3D_INST_ATTRIB_HPP

# include "Graphics/Attribute/Base/AttributeBase.hpp"

# include "Graphics/Attribute/Trans3D.hpp"

class Simple3D_InstAttrib : public Attribute::Base
{
	private:
		Attribute::Trans3D	Trans;

	public:
		Simple3D_InstAttrib(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexTransPos,
			unsigned int indexTransRot
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};

#endif
