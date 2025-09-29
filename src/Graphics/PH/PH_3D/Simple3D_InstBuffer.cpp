#include "Graphics/PH/PH_3D/Simple3D_InstBuffer.hpp"
#include "Graphics/PH/PH_3D/Simple3D_InstAttrib.hpp"
#include "Graphics/PH/PH_3D/Simple3D_InstData.hpp"



Simple3D_InstBuffer::Simple3D_InstBuffer(
	unsigned int indexTransPos,
	unsigned int indexTransRotSin,
	unsigned int indexTransRotCos
) :
	BaseBuffer(1, (AttributeBase * []) {
		new Simple3D_InstAttrib(1, sizeof(Simple3D_InstData), indexTransPos, indexTransRotSin, indexTransRotCos)
	}) { }
Simple3D_InstBuffer::~Simple3D_InstBuffer() {}
