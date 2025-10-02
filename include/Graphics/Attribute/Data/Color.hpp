
#ifndef  ATTRIB_COLOR_HPP
# define ATTRIB_COLOR_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

namespace Attribute
{
class Color : public Attribute::Base
{
	private:
		Attribute::Location Col;

	public:
		Color(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexCol
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
