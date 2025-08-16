
#ifndef POS_COL_BUFFER
# define POS_COL_BUFFER

# include "BaseBuffer.hpp"

class PosColBuffer : public BaseBuffer
{
	private:
		unsigned int * MainID;
		unsigned int Count;

	public:
		PosColBuffer();
		~PosColBuffer();

	public:
		void Data(int count, const void * data);

		void Draw();
};

#endif
