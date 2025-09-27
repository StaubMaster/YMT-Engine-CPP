#include "Graphics/Buffer/BufferArray.hpp"
#include "OpenGL/openGL.h"
#include <iostream>



BufferArray::BufferArray()
{
	glGenVertexArrays(1, &ArrayID);
}
BufferArray::~BufferArray()
{
	glDeleteVertexArrays(1, &ArrayID);
}



void BufferArray::Use()
{
	glBindVertexArray(ArrayID);
}
