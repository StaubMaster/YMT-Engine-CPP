#include "DataStruct/Main/Waveform/OBJ_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



OBJ_3D_BufferArray::OBJ_3D_BufferArray() :
	Instance_Base_BufferArray(
		new OBJ_MainBuffer(0, 1, 2, 3, 4, 5, 6, 7),
		new Simple3D_InstBuffer(20, 21),
		GL_TRIANGLES)
{

}
OBJ_3D_BufferArray::~OBJ_3D_BufferArray()
{

}
