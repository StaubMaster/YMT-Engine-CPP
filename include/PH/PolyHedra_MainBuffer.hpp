
#ifndef  POLYHEDRA_MAIN_BUFFER_HPP
# define POLYHEDRA_MAIN_BUFFER_HPP

# include "Graphics/Buffer/BaseBuffer.hpp"

class PolyHedra_MainBuffer : public BaseBuffer
{
	public:
		PolyHedra_MainBuffer(
			unsigned int indexPosition,
			unsigned int indexNormal,
			unsigned int indexTexture
		);
		~PolyHedra_MainBuffer();
};

#endif
