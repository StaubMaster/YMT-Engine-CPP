#ifndef  TEXTURE_2D_ARRAY_HPP
# define TEXTURE_2D_ARRAY_HPP

# include "Base.hpp"
# include "DataStruct/SizeRatio2D.hpp"

class FileContext;
class Image;

namespace Texture
{
class T2DArray : public Base
{
	public:
		SizeRatio2D	SizeRatio;

	public:
		T2DArray(const Image * img);
		T2DArray(unsigned int w, unsigned int h, unsigned int count, const Image ** img);
		T2DArray(const FileContext & file);
		T2DArray(unsigned int w, unsigned int h, unsigned int count, const FileContext files []);
		~T2DArray();
};
};

#endif
