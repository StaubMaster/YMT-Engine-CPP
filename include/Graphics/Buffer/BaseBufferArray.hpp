
#ifndef  BASE_BUFFER_ARRAY
# define BASE_BUFFER_ARRAY

class BaseBufferArray
{
	private:
		unsigned int ArrayID;

	protected:
		BaseBufferArray();
		virtual ~BaseBufferArray();

		//	should only be used as Pointers
		BaseBufferArray(const BaseBufferArray & other) = delete;
		BaseBufferArray & operator =(const BaseBufferArray & other) = delete;

	public:
		void Use();

		virtual void Draw() = 0;
};

#endif
