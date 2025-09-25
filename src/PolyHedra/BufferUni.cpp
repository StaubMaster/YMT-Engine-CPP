#include "PolyHedra.hpp"



PolyHedraBuffer::PolyHedraBuffer() : BaseBuffer(1),
	MainID(BufferIDs[0])
{
	Count = 0;
	std::cout << "++++ PolyHedraBuffer\n";
}
PolyHedraBuffer::~PolyHedraBuffer()
{
	std::cout << "---- PolyHedraBuffer\n";
}



void PolyHedraBuffer::Data(int count, const PolyHedra_MainData * data)
{
	int size = sizeof(PolyHedra_MainData);
	int offset = 0;
	
	Use();
	glBindBuffer(GL_ARRAY_BUFFER, MainID);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, size, (const void *)(intptr_t)offset);
	offset += sizeof(Point3D);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, size, (const void *)(intptr_t)offset);

	Count = count;
}
void PolyHedraBuffer::Draw()
{
	Use();
	glDrawArrays(GL_TRIANGLES, 0, Count);
}
