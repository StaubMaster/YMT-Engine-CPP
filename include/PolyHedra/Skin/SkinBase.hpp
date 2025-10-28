#ifndef  POLYHEDRA_SKIN_BASE_HPP
# define POLYHEDRA_SKIN_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
//# include "Texture/TextureBase.hpp"

namespace YMT
{
	class PolyHedra;
};

class TextureBase;

class PolyHedra_SkinBase
{
	protected:
		YMT::PolyHedra & PolyHedra;
	public:
		TextureBase * Texture;

	public:
		PolyHedra_SkinBase(YMT::PolyHedra & polyhedra);
		virtual ~PolyHedra_SkinBase();

	public:
		virtual void Done() = 0;
};

#endif
