#include "PolyHedraBuffer.hpp"



PolyHedraBuffer::PolyHedraBuffer() : BaseBuffer(1)
{
	MainID = &BufferIDs[0];
	Count = 0;
	std::cout << "++++ PolyHedraBuffer\n";
}
PolyHedraBuffer::~PolyHedraBuffer()
{
	std::cout << "---- PolyHedraBuffer\n";
}



void PolyHedraBuffer::Data(int count, const RenderPoint3D * data)
{
	Use();

	int size = sizeof(RenderPoint3D);
	
	glBindBuffer(GL_ARRAY_BUFFER, *MainID);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	int offset = 0;

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
