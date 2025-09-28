#include "Graphics/PH/PH_3D/PolyHedra_3D_Instances.hpp"



PolyHedra_3D_Instances::PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra)
{
	int count;
	PolyHedra_MainData * data = polyhedra -> ToMainData(count);
	Buffer.BindMain(data, count);
	delete [] data;
}
PolyHedra_3D_Instances::~PolyHedra_3D_Instances()
{

}



EntryContainerDynamic<PolyHedra_3D_InstData>::Entry * PolyHedra_3D_Instances::Alloc(int size)
{
	return Instances.Alloc(size);
}



void PolyHedra_3D_Instances::Update()
{
	if (Instances.Changed)
	{
		Buffer.BindInst(Instances.Data, Instances.Length);
		Instances.Changed = false;
	}
}
void PolyHedra_3D_Instances::Draw()
{
	Buffer.Draw();
}
