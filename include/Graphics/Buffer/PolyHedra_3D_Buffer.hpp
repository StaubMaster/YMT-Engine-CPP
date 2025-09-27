
#ifndef  POLYHEDRA_3D_BUFFER
# define POLYHEDRA_3D_BUFFER

# include "Instance_Base_Buffer.hpp"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_MainAttrib.hpp"

# include "PolyHedra_3D_InstData.hpp"
# include "PolyHedra_3D_InstAttrib.hpp"

# include "Abstract.hpp"

# include "BufferArray.hpp"
# include "BaseBuffer.hpp"



class PolyHedra_3D_Buffer : public Instance_Base_Buffer<
	PolyHedra_MainData,
	PolyHedra_MainAttrib,
	PolyHedra_3D_InstData,
	PolyHedra_3D_InstAttrib
>
{
	public:
		PolyHedra_3D_Buffer();
		~PolyHedra_3D_Buffer();
};

#endif
