#include "DataStruct/Full/PolyHedra_3D/PolyHedra_3D_Instances.hpp"
#include "PolyHedra/Skin/SkinBase.hpp"
#include "Graphics/Texture/Base.hpp"



PolyHedra_3D_Instances::PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra)
{
	int count;
	PolyHedra_MainData * data = polyhedra -> ToMainData(count);
	Buffer.BindMain(data, count);
	delete [] data;

	if (polyhedra -> Skin != NULL)
	{
		Texture = polyhedra -> Skin -> ToTexture();
	}
	else
	{
		Texture = NULL;
	}
}
PolyHedra_3D_Instances::~PolyHedra_3D_Instances()
{
	delete Texture;
}



EntryContainerDynamic<Simple3D_InstData>::Entry * PolyHedra_3D_Instances::Alloc(int size)
{
	return Instances.Alloc(size);
}



PolyHedra_3D_Instances & PolyHedra_3D_Instances::Update()
{
	if (Instances.Changed)
	{
		Buffer.BindInst(Instances.Data, Instances.Length);
		Instances.Changed = false;
	}
	return *this;
}
PolyHedra_3D_Instances & PolyHedra_3D_Instances::Draw()
{
	if (Texture != NULL)
	{
		Texture -> Bind();
	}
	Buffer.Draw();
	return *this;
}
