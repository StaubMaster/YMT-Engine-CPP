
#ifndef  BASE_BUFFER
# define BASE_BUFFER

# include "Graphics/Attribute/AttributeBase.hpp"

class BaseBuffer
{
	private:
		const unsigned int BufferCount;
		AttributeBase ** Attributes;
		unsigned int * BufferIDs;
	public:
		unsigned int Count;

	protected:
	public:
		BaseBuffer(unsigned int buffer_count, AttributeBase * attributes []);
		virtual ~BaseBuffer();

	public:
		void BindData(unsigned int target, unsigned int index, unsigned int size, const void * data, unsigned int usage);
};

#endif
