#include "DataStruct/Full/PolyHedra_3D/PolyHedra_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
//# include <iostream>



PolyHedra_3D_BufferArray::PolyHedra_3D_BufferArray() :
	Instance_Base_BufferArray(
		new PolyHedra_MainBuffer(0, 1, 2),
		new Simple3D_InstBuffer(3, 4),
		GL_TRIANGLES)
{

}
PolyHedra_3D_BufferArray::~PolyHedra_3D_BufferArray()
{

}
