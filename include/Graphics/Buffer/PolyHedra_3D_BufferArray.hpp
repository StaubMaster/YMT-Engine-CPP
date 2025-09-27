
#ifndef  POLYHEDRA_3D_BUFFER_ARRAY
# define POLYHEDRA_3D_BUFFER_ARRAY

# include "Instance_Base_BufferArray.hpp"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_MainAttrib.hpp"
# include "PolyHedra_MainBuffer.hpp"

# include "PolyHedra_3D_InstData.hpp"
# include "PolyHedra_3D_InstAttrib.hpp"
# include "PolyHedra_3D_InstBuffer.hpp"

# include "Abstract.hpp"

# include "BufferArray.hpp"
# include "BaseBuffer.hpp"



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
