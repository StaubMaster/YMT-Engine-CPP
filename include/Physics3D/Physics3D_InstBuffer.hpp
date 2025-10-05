
#ifndef  PHYSICS_3D_INST_BUFFER_HPP
# define PHYSICS_3D_INST_BUFFER_HPP

# include "Graphics/Buffer/BaseBuffer.hpp"

class Physics3D_InstBuffer : public BaseBuffer
{
	public:
		Physics3D_InstBuffer(
			unsigned int indexTransPos,
			unsigned int indexTransRotSin,
			unsigned int indexTransRotCos,
			unsigned int indexVelPos,
			unsigned int indexVelRotSin,
			unsigned int indexVelRotCos
		);
		~Physics3D_InstBuffer();
};

#endif
