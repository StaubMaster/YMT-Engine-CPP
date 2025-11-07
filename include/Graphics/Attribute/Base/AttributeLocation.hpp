
#ifndef  ATTRIBUTE_LOCATION_HPP
# define ATTRIBUTE_LOCATION_HPP

namespace Attribute
{
class Location
{
	/*
		Offset inside Data Pointer
		Size is not directly used by gl
		glPointer uses offset + Offset
		offset is increased by Size
	*/
	private:
	public:
		//	from Child
		const unsigned int Type;
		const unsigned int Size;
		const unsigned int Count;

		//	from Buffer
		const unsigned int Divisor;
		const unsigned int Stride;
		const unsigned int Index;

	public:
		Location(
			unsigned int type,
			unsigned int size,
			unsigned int count,
			unsigned int divisor,
			unsigned int stride,
			unsigned int index);
};
};

#endif
