
#ifndef  SIMPLE_3D_INST_BUFFER_HPP
# define SIMPLE_3D_INST_BUFFER_HPP

# include "Graphics/Buffer/BaseBuffer.hpp"

class Simple3D_InstBuffer : public BaseBuffer
{
	public:
		Simple3D_InstBuffer(
			unsigned int indexTransPos,
			unsigned int indexTransRot
		);
		~Simple3D_InstBuffer();
};

#endif
