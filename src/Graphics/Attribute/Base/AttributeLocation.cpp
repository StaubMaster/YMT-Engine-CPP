#include "Graphics/Attribute/Base/AttributeLocation.hpp"
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

