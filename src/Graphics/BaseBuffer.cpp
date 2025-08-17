#include "Graphics/BaseBuffer.hpp"

BaseBuffer::BaseBuffer(int count)
{
	glGenVertexArrays(1, &ArrayID);
	BufferCount = count;
	BufferIDs = new unsigned int[count];
	glGenBuffers(BufferCount, BufferIDs);
	std::cout << "++++ BaseBuffer\n";
}
BaseBuffer::~BaseBuffer()
{
	std::cout << "---- BaseBuffer\n";
	glBindVertexArray(ArrayID);
	glDeleteBuffers(BufferCount, BufferIDs);
	glDeleteVertexArrays(1, &ArrayID);
	delete [] BufferIDs;
}



void BaseBuffer::Use()
{
	glBindVertexArray(ArrayID);
}


