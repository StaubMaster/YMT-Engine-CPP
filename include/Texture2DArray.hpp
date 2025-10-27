#ifndef  TEXTURE_2D_ARRAY_HPP
# define TEXTURE_2D_ARRAY_HPP

# include "TextureBase.hpp"
# include "DataStruct/SizeRatio2D.hpp"

class FileContext;

class Texture2DArray : public TextureBase
{
	public:
		SizeRatio2D	SizeRatio;

	public:
		Texture2DArray(const FileContext & file);
		Texture2DArray(unsigned int w, unsigned int h, unsigned int count, const FileContext files []);
		~Texture2DArray();
};

#endif
