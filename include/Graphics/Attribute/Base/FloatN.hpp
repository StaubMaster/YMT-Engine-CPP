
#ifndef  ATTRIB_FLOAT_N_HPP
# define ATTRIB_FLOAT_N_HPP

# include "Graphics/Attribute/Base/AttributeLocation.hpp"
# include "Graphics/Attribute/Base/AttributeBase.hpp"

namespace Attribute
{
class FloatN : public Attribute::Base
{
	private:
		Attribute::Location Location;

	public:
		FloatN(
			unsigned int n,
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);
		FloatN(
			unsigned int divisor,
			unsigned int stride,
			unsigned int indexPos
		);

	public:
		void Bind(const unsigned char * & offset) const override;
};
};

#endif
