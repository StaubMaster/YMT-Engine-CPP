#include "Texture/TextureGen.hpp"
#include "Format/Image.hpp"



Image * TextureGen::NoSkin()
{
	Image * img = new Image(1, 1);

	img -> setPixel(0, 0, 0xFFFFFF);

	return img;
}

Image * TextureGen::Orientation2D()
{
	Image * img = new Image(2, 2);

	img -> setPixel(0, 0, 0x000000);
	img -> setPixel(1, 0, 0x0000FF);
	img -> setPixel(1, 1, 0x00FF00);
	img -> setPixel(0, 1, 0xFF0000);

	return img;
}

Image * TextureGen::Orientation3D()
{
	Image * img = new Image(8, 4);

	img -> setPixel(0, 0, 0x000000);
	img -> setPixel(1, 0, 0x0000FF);
	img -> setPixel(2, 0, 0x000000);
	img -> setPixel(3, 0, 0x00FF00);
	img -> setPixel(4, 0, 0x000000);
	img -> setPixel(5, 0, 0xFF0000);
	img -> setPixel(6, 0, 0x7F7F7F);
	img -> setPixel(7, 0, 0x7F7F7F);

	img -> setPixel(0, 1, 0x00FF00);
	img -> setPixel(1, 1, 0x00FFFF);
	img -> setPixel(2, 1, 0xFF0000);
	img -> setPixel(3, 1, 0xFFFF00);
	img -> setPixel(4, 1, 0x0000FF);
	img -> setPixel(5, 1, 0xFF00FF);
	img -> setPixel(6, 1, 0x7F7F7F);
	img -> setPixel(7, 1, 0x7F7F7F);

	img -> setPixel(0, 2, 0xFF0000);
	img -> setPixel(1, 2, 0xFF00FF);
	img -> setPixel(2, 2, 0x0000FF);
	img -> setPixel(3, 2, 0x00FFFF);
	img -> setPixel(4, 2, 0x00FF00);
	img -> setPixel(5, 2, 0xFFFF00);
	img -> setPixel(6, 2, 0x7F7F7F);
	img -> setPixel(7, 2, 0x7F7F7F);

	img -> setPixel(0, 3, 0xFFFF00);
	img -> setPixel(1, 3, 0xFFFFFF);
	img -> setPixel(2, 3, 0xFF00FF);
	img -> setPixel(3, 3, 0xFFFFFF);
	img -> setPixel(4, 3, 0x00FFFF);
	img -> setPixel(5, 3, 0xFFFFFF);
	img -> setPixel(6, 3, 0x7F7F7F);
	img -> setPixel(7, 3, 0x7F7F7F);

	return img;
}
