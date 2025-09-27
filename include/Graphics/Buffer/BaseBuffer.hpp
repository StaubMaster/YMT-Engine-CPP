
#ifndef  BASE_BUFFER
# define BASE_BUFFER

class BaseBuffer
{
	private:
		const unsigned int BufferCount;
	public:
		unsigned int * BufferIDs;
		unsigned int Count;

	protected:
	public:
		BaseBuffer(unsigned int count);
		virtual ~BaseBuffer();

	public:
		void BindData(unsigned int target, unsigned int index, unsigned int size, const void * data, unsigned int usage);

	//	Bindings
	//	do Binding in Data ?
};

#endif
