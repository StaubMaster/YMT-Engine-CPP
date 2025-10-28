#include "PolyHedra/Skin/SkinBase.hpp"
#include "Texture/TextureBase.hpp"
#include "Format/Image.hpp"



PolyHedra_SkinBase::PolyHedra_SkinBase(YMT::PolyHedra & polyhedra) :
	PolyHedra(polyhedra),
	Images()
	{ }
PolyHedra_SkinBase::~PolyHedra_SkinBase()
{
	for (unsigned int i = 0; i < Images.Count(); i++)
	{
		delete Images[i];
	}
}


