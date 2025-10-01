#include "Graphics/Attribute/AttributeLocation.hpp"
#include "OpenGL/openGL.h"



Attribute::Location::Location(
	unsigned int type,
	unsigned int size,
	unsigned int count,
	unsigned int divisor,
	unsigned int stride,
	unsigned int index
) :
	Type(type),
	Size(size),
	Count(count),
	Divisor(divisor),
	Stride(stride),
	Index(index)
{ }



void Attribute::Location::Bind(const unsigned char * & offset) const
{
	glEnableVertexAttribArray(Index);
	glVertexAttribPointer(Index, Count, Type, GL_FALSE, Stride, offset);
	glVertexAttribDivisor(Index, Divisor);
	offset += Size;
}
