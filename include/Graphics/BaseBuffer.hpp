
#ifndef BASE_BUFFER
# define BASE_BUFFER

# include <iostream>
# include "../../OpenGL/openGL.h"

class BaseBuffer
{
	private:
		unsigned int ArrayID;

	protected:
		int BufferCount;
		unsigned int * BufferIDs;

	protected:
		BaseBuffer(int count);
		virtual ~BaseBuffer();

	public:
		void Use();

		virtual void Draw() = 0;
};

#endif
