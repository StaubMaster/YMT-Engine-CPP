#include "DataStruct/Main/PolyHedra/PolyHedra_MainBuffer.hpp"
#include "DataStruct/Main/PolyHedra/PolyHedra_MainAttrib.hpp"
#include "DataStruct/Main/PolyHedra/PolyHedra_MainData.hpp"



PolyHedra_MainBuffer::PolyHedra_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexNormal,
	unsigned int indexTexture
) :
	BaseBuffer(1, (Attribute::Base * []) {
		new PolyHedra_MainAttrib(0, sizeof(PolyHedra_MainData), indexPosition, indexNormal, indexTexture)
	}) { }
PolyHedra_MainBuffer::~PolyHedra_MainBuffer() {}
