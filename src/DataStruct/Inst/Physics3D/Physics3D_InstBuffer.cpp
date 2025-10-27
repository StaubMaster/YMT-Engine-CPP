#include "DataStruct/Inst/Physics3D/Physics3D_InstBuffer.hpp"
#include "DataStruct/Inst/Physics3D/Physics3D_InstAttrib.hpp"
#include "DataStruct/Inst/Physics3D/Physics3D_InstData.hpp"



Physics3D_InstBuffer::Physics3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot,
	unsigned int indexVelPos,
	unsigned int indexVelRot
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new Physics3D_InstAttrib(1, sizeof(Physics3D_InstData), indexTransPos, indexTransRot,
		indexVelPos, indexVelRot)
	}) { }
Physics3D_InstBuffer::~Physics3D_InstBuffer() { }
