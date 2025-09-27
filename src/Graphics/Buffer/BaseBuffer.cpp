#include "Graphics/Buffer/BaseBuffer.hpp"
#include "OpenGL/openGL.h"
#include <iostream>



BaseBuffer::BaseBuffer(unsigned int buffer_count) :
	BufferCount(buffer_count)
{
	BufferIDs = new unsigned int[BufferCount];
	glGenBuffers(BufferCount, BufferIDs);
	std::cout << "++++ BaseBuffer\n";
	Count = 0;
}
BaseBuffer::~BaseBuffer()
{
	std::cout << "---- BaseBuffer\n";
	glDeleteBuffers(BufferCount, BufferIDs);
	delete [] BufferIDs;
}



void BaseBuffer::BindData(unsigned int target, unsigned int index, unsigned int size, const void * data, unsigned int usage)
{
	glBindBuffer(target, BufferIDs[index]);
	glBufferData(target, size, data, usage);
}
