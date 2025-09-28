#include "Graphics/PH/PH_3D/PolyHedra_3D_InstBuffer.hpp"
#include "Graphics/PH/PH_3D/PolyHedra_3D_InstAttrib.hpp"
#include "Graphics/PH/PH_3D/PolyHedra_3D_InstData.hpp"



PolyHedra_3D_InstBuffer::PolyHedra_3D_InstBuffer() :
	BaseBuffer(1, (AttributeBase * []) {
		new PolyHedra_3D_InstAttrib(1, sizeof(PolyHedra_3D_InstData), 3, 4, 5)
	}) { }
PolyHedra_3D_InstBuffer::~PolyHedra_3D_InstBuffer() {}
