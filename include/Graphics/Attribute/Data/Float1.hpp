
#ifndef  ATTRIB_FLOAT_1_HPP
# define ATTRIB_FLOAT_1_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

namespace Attribute
{
class Float1 : public Attribute::Base
{
	private:
		Attribute::Location Location;

	public:
		Float1(
			unsigned int divisor,
			unsigned int stride,
			unsigned int index
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
