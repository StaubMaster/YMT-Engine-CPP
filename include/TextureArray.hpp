#ifndef TEXTURE_ARRAY_HPP
# define TEXTURE_ARRAY_HPP

# include "DataStruct/SizeRatio2D.hpp"

class FileContext;

class TextureArray
{
	private:
		unsigned int GL_TextureArray;
	public:
		SizeRatio2D	SizeRatio;

	public:
		TextureArray(const FileContext & file);
		TextureArray(unsigned int w, unsigned int h, unsigned int count, const FileContext files []);
		~TextureArray();

	public:
		void Bind();
};

#endif
