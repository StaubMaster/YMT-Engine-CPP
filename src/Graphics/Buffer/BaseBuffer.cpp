#include "Graphics/Buffer/BaseBuffer.hpp"
#include "Graphics/Attribute/Base/AttributeBase.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



BaseBuffer::BaseBuffer(unsigned int buffer_count, Attribute::Base * attributes []) :
	BufferCount(buffer_count)
{
	BufferIDs = new unsigned int[BufferCount];
	glGenBuffers(BufferCount, BufferIDs);

	Attributes = new Attribute::Base * [BufferCount];
	for (unsigned int i = 0; i < BufferCount; i++) { Attributes[i] = attributes[i]; }

	std::cout << "++++ BaseBuffer\n";
	Count = 0;
}
BaseBuffer::~BaseBuffer()
{
	std::cout << "---- BaseBuffer\n";

	glDeleteBuffers(BufferCount, BufferIDs);
	delete [] BufferIDs;

	for (unsigned int i = 0; i < BufferCount; i++) { delete Attributes[i]; }
	delete [] Attributes;
}



void BaseBuffer::BindData(unsigned int target, unsigned int index, unsigned int size, const void * data, unsigned int usage)
{
	glBindBuffer(target, BufferIDs[index]);
	glBufferData(target, size, data, usage);

	const unsigned char * offset = 0;
	Attributes[index] -> Bind(offset);
}
