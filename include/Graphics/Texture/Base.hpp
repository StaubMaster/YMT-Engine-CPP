#ifndef  TEXTURE_BASE_HPP
# define TEXTURE_BASE_HPP

class FileContext;

namespace Texture
{
class Base
{
	private:
		unsigned int GL_Texture;
		unsigned int Type;

	public:
		Base(unsigned int type);
		virtual ~Base();

	public:
		virtual void Bind();
};
};

#endif
