
#ifndef PNG_IMAGE_HPP
# define PNG_IMAGE_HPP
# include <iostream>
# include <fstream>
# include <sstream>

# include "../../FileManager/FileContext.hpp"
# include "../../FileManager/Image.hpp"
# include "../DebugManager.hpp"
# include "../uint.hpp"
# include "../BitStream.hpp"

class PNG_Image
{
	private:
		struct IHDR
		{
			uint32	width;
			uint32	height;

			uint8	bit_depth;
			uint8	color_type;

			uint8	compression_method;
			uint8	filter_method;
			uint8	interlace_method;

			IHDR();
			IHDR(BitStream & bits);

			void	ToString(std::ostream & os) const;
		};

	public:
		static Image * Load(const FileContext & file, bool debug = false);

		class PNG_Exception_NotImplemented : public std::exception { public: const char * what() const throw(); };
		class PNG_Exception_InvalidData : public std::exception { public: const char * what() const throw(); };
		class PNG_Exception_BadFile : public std::exception { public: const char * what() const throw(); };
		class PNG_Exception_Signature : public std::exception { public: const char * what() const throw(); };
};

#endif
