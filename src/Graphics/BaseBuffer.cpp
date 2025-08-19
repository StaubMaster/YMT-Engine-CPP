#include "Graphics/BaseBuffer.hpp"

BaseBuffer::BaseBuffer(int count)
{
	BufferCount = count;
	BufferIDs = new unsigned int[count];
	glGenVertexArrays(1, &ArrayID);
	glBindVertexArray(ArrayID);
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


