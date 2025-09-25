
#include "Graphics/Buffer/PolyHedra_3D_Buffer.hpp"

PolyHedra_3D_Buffer::PolyHedra_3D_Buffer()
{
	glGenVertexArrays(1, &BufferArray);
	glBindVertexArray(BufferArray);
	glGenBuffers(1, &MainBuffer);
	glGenBuffers(1, &InstBuffer);
	MainCount = 0;
	InstCount = 0;
}
PolyHedra_3D_Buffer::~PolyHedra_3D_Buffer()
{
	glDeleteBuffers(1, &MainBuffer);
	glDeleteBuffers(1, &InstBuffer);
	glDeleteVertexArrays(1, &BufferArray);
}





void PolyHedra_3D_Buffer::BindMain(const PolyHedra_MainData * data, unsigned int count)
{
	int size = sizeof(PolyHedra_MainData);
	int offset = 0;

	glBindVertexArray(BufferArray);
	glBindBuffer(GL_ARRAY_BUFFER, MainBuffer);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	offset += sizeof(Point3D);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	offset += sizeof(Point3D);

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	offset += sizeof(Point2D);

	MainCount = count;
}
void PolyHedra_3D_Buffer::BindInst(const PolyHedra_3D_InstData * data, unsigned int count)
{
	int size = sizeof(Transformation3D);
	int offset = 0;

	glBindVertexArray(BufferArray);
	glBindBuffer(GL_ARRAY_BUFFER, InstBuffer);
	glBufferData(GL_ARRAY_BUFFER, size * count, data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(3, 1);
	offset += sizeof(Point3D);

	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(4, 1);
	offset += sizeof(float) * 3;

	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, size, (const void *)(intptr_t)offset);
	glVertexAttribDivisor(5, 1);
	offset += sizeof(float) * 3;

	InstCount = count;
}
//PolyHedra_3D_Buffer::BindTex(const  * data, int len) { }





void PolyHedra_3D_Buffer::Update()
{
	if (Instances.Changed)
	{
		BindInst(Instances.Data, Instances.Length);
		Instances.Changed = false;
	}
}
void PolyHedra_3D_Buffer::Draw()
{
	glBindVertexArray(BufferArray);
	glDrawArraysInstanced(GL_TRIANGLES, 0, MainCount, InstCount);
}
