#include "Physics3D/Physics3D_InstBuffer.hpp"
#include "Physics3D/Physics3D_InstAttrib.hpp"
#include "Physics3D/Physics3D_InstData.hpp"



Physics3D_InstBuffer::Physics3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRotSin,
	unsigned int indexTransRotCos,
	unsigned int indexVelPos,
	unsigned int indexVelRotSin,
	unsigned int indexVelRotCos
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new Physics3D_InstAttrib(1, sizeof(Physics3D_InstData), indexTransPos, indexTransRotSin, indexTransRotCos,
		indexVelPos, indexVelRotSin, indexVelRotCos)
	}) { }
Physics3D_InstBuffer::~Physics3D_InstBuffer() { }
