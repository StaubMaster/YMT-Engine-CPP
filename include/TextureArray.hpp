#ifndef TEXTURE_ARRAY_HPP
# define TEXTURE_ARRAY_HPP

# include "FileManager/FileContext.hpp"
# include "DataStruct/SizeRatio2D.hpp"

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