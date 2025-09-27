
#ifndef  INSTANCE_BASE_BUFFER
# define INSTANCE_BASE_BUFFER

# include <iostream>
# include "OpenGL/openGL.h"

# include "BufferArray.hpp"
# include "BaseBuffer.hpp"

# include "Graphics/Attribute/AttributeBase.hpp"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_MainAttrib.hpp"

# include "PolyHedra_3D_InstData.hpp"
# include "PolyHedra_3D_InstAttrib.hpp"

# include "Abstract.hpp"

template<
	typename MainDataType,
	typename InstDataType,
	typename MainBufferType,
	typename InstBufferType
>
class Instance_Base_BufferArray : public BufferArray
{
	protected:
	private:
		MainBufferType MainBuffer;
		InstBufferType InstBuffer;

		unsigned int DrawMode;

	public:
	protected:
		Instance_Base_BufferArray(
			unsigned int draw_mode
		) : BufferArray(),
			MainBuffer(),
			InstBuffer(),
			DrawMode(draw_mode) { }
		~Instance_Base_BufferArray() { }

	public:
		void BindMain(const MainDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			Use();
			MainBuffer.BindData(GL_ARRAY_BUFFER, buffer_index, sizeof(MainDataType) * count, data, GL_STATIC_DRAW);
			MainBuffer.Count = count;
		}
		void BindInst(const InstDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			Use();
			InstBuffer.BindData(GL_ARRAY_BUFFER, buffer_index, sizeof(InstDataType) * count, data, GL_STREAM_DRAW);
			InstBuffer.Count = count;
		}

	public:
		void Draw() override
		{
			Use();
			glDrawArraysInstanced(DrawMode, 0, MainBuffer.Count, InstBuffer.Count);
		}
};

#endif
