#include "PolyHedra.hpp"



YMT::PolyHedra::BufferInst::BufferInst() : BaseBuffer(2),
	MainID(BufferIDs[0]),
	InstID(BufferIDs[1])
{
	MainCount = 0;
	InstCount = 0;
	std::cout << "++++ BufferInst\n";
}
YMT::PolyHedra::BufferInst::~BufferInst()
{
	std::cout << "---- BufferInst\n";
}



void YMT::PolyHedra::BufferInst::DataPolyHedra(int count, const PolyHedra_MainData * data)
{
	int size = sizeof(PolyHedra_MainData);
	int offset = 0;

	Use();
	glBindBuffer(GL_ARRAY_BUFFER, MainID);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	offset += sizeof(Point3D);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	offset += sizeof(float) * 3;

	MainCount = count;
}
void YMT::PolyHedra::BufferInst::DataTrans(int count, const Transformation3D * data)
{
	int size = sizeof(Transformation3D);
	int offset = 0;

	Use();
	glBindBuffer(GL_ARRAY_BUFFER, InstID);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(2, 1);
	offset += sizeof(Point3D);

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(3, 1);
	offset += sizeof(float) * 3;

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(4, 1);
	offset += sizeof(float) * 3;

	InstCount = count;
}
void YMT::PolyHedra::BufferInst::Draw()
{
	Use();
	glDrawArraysInstanced(GL_TRIANGLES, 0, MainCount, InstCount);
}
