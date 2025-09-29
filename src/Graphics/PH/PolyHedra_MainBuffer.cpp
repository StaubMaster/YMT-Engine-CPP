#include "Graphics/PH/PolyHedra_MainBuffer.hpp"
#include "Graphics/PH/PolyHedra_MainAttrib.hpp"
#include "Graphics/PH/PolyHedra_MainData.hpp"



PolyHedra_MainBuffer::PolyHedra_MainBuffer(
	unsigned int indexPosition,
	unsigned int indexNormal,
	unsigned int indexTexture
) :
	BaseBuffer(1, (AttributeBase * []) {
		new PolyHedra_MainAttrib(0, sizeof(PolyHedra_MainData), indexPosition, indexNormal, indexTexture)
	}) { }
PolyHedra_MainBuffer::~PolyHedra_MainBuffer() {}
