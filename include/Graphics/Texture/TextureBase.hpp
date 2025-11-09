#ifndef  TEXTURE_HPP
# define TEXTURE_HPP

class FileContext;

class TextureBase
{
	private:
		unsigned int GL_Texture;
		unsigned int Type;

	public:
		TextureBase(unsigned int type);
		virtual ~TextureBase();

	public:
		virtual void Bind();
};

#endif
