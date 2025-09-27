
#ifndef  BUFFER_ARRAY
# define BUFFER_ARRAY

class BufferArray
{
	private:
		unsigned int ArrayID;

	protected:
		BufferArray();
		virtual ~BufferArray();

	public:
		void Use();

		virtual void Draw() = 0;
};

#endif
