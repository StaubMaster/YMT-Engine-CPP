
#ifndef  BASE_BUFFER_ARRAY
# define BASE_BUFFER_ARRAY

class BaseBufferArray
{
	private:
		unsigned int ArrayID;

	protected:
		BaseBufferArray();
		virtual ~BaseBufferArray();

	public:
		void Use();

		virtual void Draw() = 0;
};

#endif
