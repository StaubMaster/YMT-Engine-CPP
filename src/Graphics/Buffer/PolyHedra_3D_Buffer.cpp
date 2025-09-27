#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"

#include "Graphics/Attribute/AttributeLocation.hpp"
#include "Graphics/Attribute/AttributeBase.hpp"

#include "Graphics/Attribute/AttribPoint3D.hpp"
#include "Graphics/Attribute/AttribAngle3D.hpp"

#include "Graphics/Attribute/AttribPoint2D.hpp"
#include "Graphics/Attribute/AttribTrans3D.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



PolyHedra_3D_Buffer::PolyHedra_3D_Buffer() :
	Instance_Base_Buffer(
		1, PolyHedra_MainAttrib(0, sizeof(PolyHedra_MainData), 0, 1, 2),
		1, PolyHedra_3D_InstAttrib(1, sizeof(PolyHedra_3D_InstData), 3, 4, 5),
		GL_TRIANGLES
	)
{

}
PolyHedra_3D_Buffer::~PolyHedra_3D_Buffer()
{

}

/*PolyHedra_3D_Buffer::PolyHedra_3D_Buffer() :
	BufferArray(),
	MainBuffer(1),
	InstBuffer(1),
	MainAttrib(0, sizeof(PolyHedra_MainData), 0, 1, 2),
	InstAttrib(1, sizeof(PolyHedra_3D_InstData), 3, 4, 5)
{

}
PolyHedra_3D_Buffer::~PolyHedra_3D_Buffer()
{

}



void PolyHedra_3D_Buffer::BindMain(const PolyHedra_MainData * data, unsigned int count)
{
	unsigned int stride = sizeof(PolyHedra_MainData);
	const unsigned char * offset = 0;

	Use();
	MainBuffer.BindData(GL_ARRAY_BUFFER, 0, stride * count, data, GL_STATIC_DRAW);
	MainAttrib.Bind(offset);
	MainBuffer.Count = count;
}
void PolyHedra_3D_Buffer::BindInst(const PolyHedra_3D_InstData * data, unsigned int count)
{
	unsigned int stride = sizeof(PolyHedra_3D_InstData);
	const unsigned char * offset = 0;

	Use();
	InstBuffer.BindData(GL_ARRAY_BUFFER, 0, stride * count, data, GL_STREAM_DRAW);
	InstAttrib.Bind(offset);
	InstBuffer.Count = count;
}
//PolyHedra_3D_Buffer::BindTex(const  * data, int len) { }





void PolyHedra_3D_Buffer::Draw()
{
	Use();
	glDrawArraysInstanced(GL_TRIANGLES, 0, MainBuffer.Count, InstBuffer.Count);
}*/
