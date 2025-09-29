#include "OBJ/OBJ_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
# include <iostream>



OBJ_3D_BufferArray::OBJ_3D_BufferArray() :
	Instance_Base_BufferArray(
		new OBJ_MainBuffer(0, 1, 2),
		new Simple3D_InstBuffer(3, 4, 5),
		GL_TRIANGLES)
{

}
OBJ_3D_BufferArray::~OBJ_3D_BufferArray()
{

}
