
#ifndef  ATTRIBUTE_LOCATION_HPP
# define ATTRIBUTE_LOCATION_HPP

namespace Attribute
{
class Location
{
	private:
	public:
		//	set from Child
		const unsigned int Type;
		const unsigned int Size;
		const unsigned int Count;

		//	set from outside
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

	public:
		void Bind(const unsigned char * & offset) const;
};
};

#endif
