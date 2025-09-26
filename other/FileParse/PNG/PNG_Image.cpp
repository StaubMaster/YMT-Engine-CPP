
#include "../DataStream.hpp"
#include "PNG_Image.hpp"
#include "Chunk.hpp"
#include "ZLIB.hpp"
#include "Huffman.hpp"
#include "DEFLATE.hpp"
#include "PNG_Filter.hpp"



PNG_Image::IHDR::IHDR()
{
	
}
PNG_Image::IHDR::IHDR(BitStream & bits)
{
	width = bits.byte32(BITSTREAM_REV);
	height = bits.byte32(BITSTREAM_REV);

	bit_depth = bits.byte8();
	color_type = bits.byte8();

	compression_method = bits.byte8();
	filter_method = bits.byte8();
	interlace_method = bits.byte8();
}
void	PNG_Image::IHDR::ToString(std::ostream & os) const
{
	os << " width: " << width << "\n";
	os << "height: " << height << "\n";

	os << " bit_depth: " << (uint16)bit_depth << "\n";
	os << "color_type: " << (uint16)color_type << "\n";

	os << "compression_method: " << (uint16)compression_method << "\n";
	os << "     filter_method: " << (uint16)filter_method << "\n";
	os << "  interlace_method: " << (uint16)interlace_method << "\n";
}



Image * PNG_Image::Load(const FileContext & file, bool debug)
{
	(void)debug;
	DebugManager::SetOut(false);
	std::ostream & os = DebugManager::GetOut();
	Image * img = NULL;

	try
	{
		os << "loading '" << file.FilePath << "' ...\n";
		std::string file_str = file.LoadText();

		os << "file length: " << file_str.size() << "\n";
		BitStream file(file_str);

		os << "\n";
		{
			uint64	signature_template = 0x0A1A0A0D474E5089;
			uint64	signature_received;

			signature_received = file.byte64();
			os << "signature\n";
			os << "template: " << uint_Hex(signature_template) << "\n";
			os << "received: " << uint_Hex(signature_received) << "\n";

			if (signature_received != signature_template)
				throw PNG_Exception_Signature();
		}
		os << "\n";

		IHDR imageHead;
		DataStream imageData(0);

		while (1)
		{
			os << "\n";
			Chunk chunk(file);
			BitStream chunk_stream = chunk.ToBitStream();
			os << chunk.ToString();
			os << "\n";
			if (chunk.isIHRD())
			{
				imageHead = IHDR(chunk_stream);
				imageHead.ToString(os);
			}
			if (chunk.isIDAT())
			{
				imageData.Concatenation(chunk_stream.Data, chunk_stream.Len);
			}
			if (chunk.isIEND())
				break;
		}

		BitStream bits(imageData.Data, imageData.Len);

		DataStream * data = new DataStream(0xFFFFFFFF);
		ZLIB::decompress(bits, *data);

		img = new Image(imageHead.width, imageHead.height);
		PNG_Filter::filter(*data, *img);
		delete data;

		return (img);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception while loading Image: " << e.what() << "\n";
		if (img != NULL)
		{
			delete img;
		}
	}
	return (NULL);
}



const char * PNG_Image::PNG_Exception_NotImplemented::what() const throw() { return "Not Implemented"; }
const char * PNG_Image::PNG_Exception_InvalidData::what() const throw() { return "Invalid Data"; }
const char * PNG_Image::PNG_Exception_BadFile::what() const throw() { return "Bad File"; }
const char * PNG_Image::PNG_Exception_Signature::what() const throw() { return "Bad Signature"; }

