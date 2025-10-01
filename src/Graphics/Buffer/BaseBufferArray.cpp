#include "Graphics/Buffer/BaseBufferArray.hpp"

#include "OpenGL/openGL.h"
//#include <iostream>


BaseBufferArray::BaseBufferArray()
{
	glGenVertexArrays(1, &ArrayID);
}
BaseBufferArray::~BaseBufferArray()
{
	glDeleteVertexArrays(1, &ArrayID);
}



void BaseBufferArray::Use()
{
	glBindVertexArray(ArrayID);
}
