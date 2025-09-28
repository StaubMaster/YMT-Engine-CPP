
#include "../../Parsing/DataStream.hpp"
#include "../../Parsing/DebugManager.hpp"

#include "PNG.hpp"
#include "PNG_IHDR.hpp"
#include "Chunk.hpp"
#include "ZLIB.hpp"
#include "Huffman.hpp"
#include "DEFLATE.hpp"
#include "PNG_Filter.hpp"

# include <iostream>
# include <fstream>
# include <sstream>



Image * PNG::Load(const FileContext & file, bool debug)
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
			{
				throw PNG_Exception_Signature();
			}
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



const char * PNG::PNG_Exception_Signature::what() const throw() { return "Bad Signature"; }
