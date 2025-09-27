
#ifndef  INSTANCE_BASE_BUFFER
# define INSTANCE_BASE_BUFFER

# include <iostream>
# include "OpenGL/openGL.h"

# include "BufferArray.hpp"
# include "BaseBuffer.hpp"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_MainAttrib.hpp"

# include "PolyHedra_3D_InstData.hpp"
# include "PolyHedra_3D_InstAttrib.hpp"

# include "Abstract.hpp"

template<
	typename MainDataType,
	typename MainAttribType,
	typename InstDataType,
	typename InstAttribType
>
class Instance_Base_Buffer : public BufferArray
{
	protected:
	private:
		BaseBuffer MainBuffer;
		BaseBuffer InstBuffer;

		MainAttribType MainAttrib;
		InstAttribType InstAttrib;

		unsigned int DrawMode;

	public:
	protected:
		Instance_Base_Buffer(
			unsigned int main_buffer_count,
			MainAttribType main_attrib,
			unsigned int inst_buffer_count,
			InstAttribType inst_attrib,
			unsigned int draw_mode
		) : BufferArray(),
			MainBuffer(main_buffer_count),
			InstBuffer(inst_buffer_count),
			MainAttrib(main_attrib),
			InstAttrib(inst_attrib),
			DrawMode(draw_mode) { }
		~Instance_Base_Buffer() { }

	public:
		void BindMain(const MainDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			unsigned int stride = sizeof(MainDataType);
			const unsigned char * offset = 0;
			Use();
			MainBuffer.BindData(GL_ARRAY_BUFFER, buffer_index, stride * count, data, GL_STATIC_DRAW);
			MainAttrib.Bind(offset);
			MainBuffer.Count = count;
		}
		void BindInst(const InstDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			unsigned int stride = sizeof(InstDataType);
			const unsigned char * offset = 0;
			Use();
			InstBuffer.BindData(GL_ARRAY_BUFFER, buffer_index, stride * count, data, GL_STREAM_DRAW);
			InstAttrib.Bind(offset);
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
