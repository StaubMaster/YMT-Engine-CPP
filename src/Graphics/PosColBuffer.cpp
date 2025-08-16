#include "../../include/Graphics/PosColBuffer.hpp"



PosColBuffer::PosColBuffer() : BaseBuffer(1)
{
	MainID = &BufferIDs[0];
	Count = 0;
	std::cout << "++++ PosColBuffer\n";
}
PosColBuffer::~PosColBuffer()
{
	std::cout << "---- PosColBuffer\n";
}



void PosColBuffer::Data(int count, const void * data)
{
	Use();

	int size = sizeof(float) * 5;

	glBindBuffer(GL_ARRAY_BUFFER, *MainID);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, size, (void *)(sizeof(float) * 0));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, false, size, (void *)(sizeof(float) * 3));

	Count = count;
}
void PosColBuffer::Draw()
{
	Use();
	glDrawArrays(GL_TRIANGLES, 0, Count);
}
