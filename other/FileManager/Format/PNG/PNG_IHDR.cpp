#include "PNG_IHDR.hpp"



IHDR::IHDR()
{
	
}
IHDR::IHDR(BitStream & bits)
{
	width = bits.byte32(BITSTREAM_REV);
	height = bits.byte32(BITSTREAM_REV);

	bit_depth = bits.byte8();
	color_type = bits.byte8();

	compression_method = bits.byte8();
	filter_method = bits.byte8();
	interlace_method = bits.byte8();
}
void	IHDR::ToString(std::ostream & os) const
{
	os << " width: " << width << "\n";
	os << "height: " << height << "\n";

	os << " bit_depth: " << (uint16)bit_depth << "\n";
	os << "color_type: " << (uint16)color_type << "\n";

	os << "compression_method: " << (uint16)compression_method << "\n";
	os << "     filter_method: " << (uint16)filter_method << "\n";
	os << "  interlace_method: " << (uint16)interlace_method << "\n";
}
