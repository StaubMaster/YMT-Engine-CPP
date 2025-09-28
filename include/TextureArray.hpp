#ifndef TEXTURE_ARRAY_HPP
# define TEXTURE_ARRAY_HPP

# include "FileManager/FileContext.hpp"

class TextureArray
{
	private:
		unsigned int GL_TextureArray;

	public:
		TextureArray(unsigned int w, unsigned int h, unsigned int count, const FileContext files []);
		~TextureArray();

	public:
		void Bind();
};

#endif