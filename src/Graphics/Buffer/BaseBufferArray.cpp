#include "Graphics/Buffer/BaseBufferArray.hpp"
#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
//#include <iostream>


BaseBufferArray::BaseBufferArray()
{
	glGenVertexArrays(1, &ArrayID);
	Debug::Log << "++++ BaseBufferArray " << ArrayID << Debug::Done;
}
BaseBufferArray::~BaseBufferArray()
{
	Debug::Log << "---- BaseBufferArray " << ArrayID << Debug::Done;
	glDeleteVertexArrays(1, &ArrayID);
}



void BaseBufferArray::Use()
{
	glBindVertexArray(ArrayID);
}
