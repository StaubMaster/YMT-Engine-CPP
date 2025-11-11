#include "Graphics/Buffer/BaseBuffer.hpp"
#include "Graphics/Attribute/Base/AttributeBase.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



BaseBuffer::BaseBuffer(unsigned int buffer_count, Attribute::Base * attributes []) :
	BufferCount(buffer_count)
{
	BufferIDs = new unsigned int[BufferCount];
	glGenBuffers(BufferCount, BufferIDs);

	Attributes = new Attribute::Base * [BufferCount];
	for (unsigned int i = 0; i < BufferCount; i++) { Attributes[i] = attributes[i]; }


	Debug::Log << "++++ BaseBuffer ";
	Debug::Log << "[" << BufferCount << "]";
	for (unsigned int i = 0; i < BufferCount; i++)
	{
		Debug::Log << " " << BufferIDs[i];
	}
	Debug::Log << Debug::Done;
	Count = 0;
}
BaseBuffer::~BaseBuffer()
{
	Debug::Log << "---- BaseBuffer";
	Debug::Log << "[" << BufferCount << "]";
	for (unsigned int i = 0; i < BufferCount; i++)
	{
		Debug::Log << " " << BufferIDs[i];
	}
	Debug::Log << Debug::Done;

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
