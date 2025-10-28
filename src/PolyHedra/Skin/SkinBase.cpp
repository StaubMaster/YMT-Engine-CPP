#include "PolyHedra/Skin/SkinBase.hpp"
#include "Texture/TextureBase.hpp"



PolyHedra_SkinBase::PolyHedra_SkinBase(YMT::PolyHedra & polyhedra) :
	PolyHedra(polyhedra),
	Texture(NULL)
	{ }
PolyHedra_SkinBase::~PolyHedra_SkinBase()
{
	delete Texture;
}


