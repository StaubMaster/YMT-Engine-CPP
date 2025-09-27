#include "Graphics/Buffer/PolyHedra_MainBuffer.hpp"
#include "Graphics/Buffer/PolyHedra_MainAttrib.hpp"
#include "Graphics/Buffer/PolyHedra_MainData.hpp"



PolyHedra_MainBuffer::PolyHedra_MainBuffer() :
	BaseBuffer(1, (AttributeBase * []) {
		new PolyHedra_MainAttrib(0, sizeof(PolyHedra_MainData), 0, 1, 2)
	}) { }
PolyHedra_MainBuffer::~PolyHedra_MainBuffer() {}
