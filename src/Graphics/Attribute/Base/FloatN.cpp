#include "Graphics/Attribute/Base/FloatN.hpp"
#include "OpenGL/openGL.h"



Attribute::FloatN::FloatN(
	unsigned int n,
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Location(GL_FLOAT, sizeof(float) * n, n, divisor, stride, indexPos)
{ }

Attribute::FloatN::FloatN(
	unsigned int divisor,
	unsigned int stride,
	unsigned int indexPos
) :
	Location(GL_FLOAT, sizeof(float), 1, divisor, stride, indexPos)
{ }



void Attribute::FloatN::Bind(const unsigned char * & offset) const
{
	glEnableVertexAttribArray(Location.Index);
	glVertexAttribPointer(Location.Index, Location.Count, Location.Type, GL_FALSE, Location.Stride, offset);
	glVertexAttribDivisor(Location.Index, Location.Divisor);
	offset += Location.Size;
}
