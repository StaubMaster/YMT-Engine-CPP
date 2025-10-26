
#ifndef  POLYHEDRA_3D_BUFFER_ARRAY_HPP
# define POLYHEDRA_3D_BUFFER_ARRAY_HPP

# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"

# include "PH/PolyHedra_MainData.hpp"
# include "PH/PolyHedra_MainBuffer.hpp"

# include "Simple3D/Simple3D_InstData.hpp"
# include "Simple3D/Simple3D_InstBuffer.hpp"



class PolyHedra_3D_BufferArray : public Instance_Base_BufferArray<
	PolyHedra_MainData,
	PolyHedra_MainBuffer,
	Simple3D_InstData,
	Simple3D_InstBuffer
>
{
	public:
		PolyHedra_3D_BufferArray();
		~PolyHedra_3D_BufferArray();
};

#endif
