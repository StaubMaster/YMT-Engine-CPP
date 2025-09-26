#ifndef TEXTURE_ARRAY_HPP
# define TEXTURE_ARRAY_HPP

# include "OpenGL/openGL.h"
# include <iostream>
# include "FileManager/FileContext.hpp"
# include "FileParse/PNG/PNG_Image.hpp"

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