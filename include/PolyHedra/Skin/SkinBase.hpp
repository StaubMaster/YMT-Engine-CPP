#ifndef  POLYHEDRA_SKIN_BASE_HPP
# define POLYHEDRA_SKIN_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
//# include "Texture/TextureBase.hpp"

namespace YMT
{
	class PolyHedra;
};

class TextureBase;
class FileContext;
class Image;

class PolyHedra_SkinBase
{
	protected:
		YMT::PolyHedra & PolyHedra;
	public:
		ContainerDynamic<Image *> Images;

	public:
		PolyHedra_SkinBase(YMT::PolyHedra & polyhedra);
		virtual ~PolyHedra_SkinBase();

	public:
		static PolyHedra_SkinBase * Load(const FileContext & file);

	public:
		virtual void Done() = 0;

		virtual TextureBase * ToTexture() const = 0;
};

#endif
