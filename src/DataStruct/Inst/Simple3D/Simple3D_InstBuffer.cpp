#include "DataStruct/Inst/Simple3D/Simple3D_InstBuffer.hpp"
#include "DataStruct/Inst/Simple3D/Simple3D_InstAttrib.hpp"
#include "DataStruct/Inst/Simple3D/Simple3D_InstData.hpp"



Simple3D_InstBuffer::Simple3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRot
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new Simple3D_InstAttrib(1, sizeof(Simple3D_InstData), indexTransPos, indexTransRot)
	}) { }
Simple3D_InstBuffer::~Simple3D_InstBuffer() {}
