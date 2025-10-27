#include "Texture2DArray.hpp"

#include "Format/Image.hpp"
#include "FileContext.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



Texture2DArray::Texture2DArray(const FileContext & file)
	: TextureBase(GL_TEXTURE_2D_ARRAY)
{
	Image * img = file.LoadImagePNG();
	SizeRatio = SizeRatio2D(img -> W, img -> H);
	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, img -> W, img -> H, 1, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, img -> Data32);
	delete img;

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
}
Texture2DArray::Texture2DArray(unsigned int w, unsigned int h, unsigned int count, const FileContext files [])
	: TextureBase(GL_TEXTURE_2D_ARRAY)
{
	SizeRatio = SizeRatio2D(w, h);

	glTexImage3D(GL_TEXTURE_2D_ARRAY, 0, GL_RGBA8, w, h, count, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, NULL);

	for (unsigned int i = 0; i < count; i++)
	{
		Image * img = files[i].LoadImagePNG();
		if (img == NULL) { img = Image::Missing(); }
		Image * scaled = img -> Scale(w, h);
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, i, w, h, 1, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8_REV, scaled -> Data32);
		delete scaled;
		delete img;
	}

	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
}
Texture2DArray::~Texture2DArray()
{

}
