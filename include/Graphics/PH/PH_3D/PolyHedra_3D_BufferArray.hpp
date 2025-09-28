
#ifndef  POLYHEDRA_3D_BUFFER_ARRAY
# define POLYHEDRA_3D_BUFFER_ARRAY

# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"

# include "Graphics/PH/PolyHedra_MainData.hpp"
# include "Graphics/PH/PolyHedra_MainBuffer.hpp"

# include "PolyHedra_3D_InstData.hpp"
# include "PolyHedra_3D_InstBuffer.hpp"



class PolyHedra_3D_BufferArray : public Instance_Base_BufferArray<
	PolyHedra_MainData,
	PolyHedra_3D_InstData,
	PolyHedra_MainBuffer,
	PolyHedra_3D_InstBuffer
>
{
	public:
		PolyHedra_3D_BufferArray();
		~PolyHedra_3D_BufferArray();
};

#endif
