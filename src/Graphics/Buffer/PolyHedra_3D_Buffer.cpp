#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"

#include "Graphics/Attribute/AttributeLocation.hpp"
#include "Graphics/Attribute/AttributeBase.hpp"

#include "Graphics/Attribute/AttribPoint3D.hpp"
#include "Graphics/Attribute/AttribAngle3D.hpp"

#include "Graphics/Attribute/AttribPoint2D.hpp"
#include "Graphics/Attribute/AttribTrans3D.hpp"



PolyHedra_3D_Buffer::PolyHedra_3D_Buffer() :
	BufferArray(),
	Main(1), Inst(1)
{

}
PolyHedra_3D_Buffer::~PolyHedra_3D_Buffer()
{

}



void PolyHedra_3D_Buffer::BindMain(const PolyHedra_MainData * data, unsigned int count)
{
	unsigned int stride = sizeof(PolyHedra_MainData);
	
	Use();
	Main.BindData(GL_ARRAY_BUFFER, 0, stride * count, data, GL_STATIC_DRAW);
	
	AttribPoint3D attrib0(0, stride, 0);
	AttribPoint3D attrib1(0, stride, 1);
	AttribPoint2D attrib2(0, stride, 2);

	const unsigned char * offset = 0;
	attrib0.Bind(offset);
	attrib1.Bind(offset);
	attrib2.Bind(offset);

	Main.Count = count;
}
void PolyHedra_3D_Buffer::BindInst(const PolyHedra_3D_InstData * data, unsigned int count)
{
	unsigned int stride = sizeof(Transformation3D);
	
	Use();
	Inst.BindData(GL_ARRAY_BUFFER, 0, stride * count, data, GL_STREAM_DRAW);

	AttribTrans3D attrib0(1, stride, 3, 4, 5);

	const unsigned char * offset = 0;
	attrib0.Bind(offset);

	Inst.Count = count;
}
//PolyHedra_3D_Buffer::BindTex(const  * data, int len) { }





void PolyHedra_3D_Buffer::Draw()
{
	Use();
	glDrawArraysInstanced(GL_TRIANGLES, 0, Main.Count, Inst.Count);
}
