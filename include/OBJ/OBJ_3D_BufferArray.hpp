
#ifndef  OBJ_3D_BUFFER_ARRAY_HPP
# define OBJ_3D_BUFFER_ARRAY_HPP

# include "Graphics/Buffer/Instance_Base_BufferArray.hpp"

# include "OBJ_Main.hpp"

# include "Graphics/PH/PH_3D/Simple3D_InstData.hpp"
# include "Graphics/PH/PH_3D/Simple3D_InstBuffer.hpp"



class OBJ_3D_BufferArray : public Instance_Base_BufferArray<
	OBJ_MainData,
	OBJ_MainBuffer,
	Simple3D_InstData,
	Simple3D_InstBuffer
>
{
	public:
		OBJ_3D_BufferArray();
		~OBJ_3D_BufferArray();
};

#endif
