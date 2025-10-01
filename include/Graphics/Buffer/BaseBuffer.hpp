
#ifndef  BASE_BUFFER
# define BASE_BUFFER

//# include "Graphics/Attribute/AttributeBase.hpp"

namespace Attribute
{
	class Base;
};

class BaseBuffer
{
	private:
		const unsigned int BufferCount;
		Attribute::Base ** Attributes;
		unsigned int * BufferIDs;
	public:
		unsigned int Count;

	protected:
	public:
		BaseBuffer(unsigned int buffer_count, Attribute::Base * attributes []);
		virtual ~BaseBuffer();

	public:
		void BindData(unsigned int target, unsigned int index, unsigned int size, const void * data, unsigned int usage);
};

#endif
