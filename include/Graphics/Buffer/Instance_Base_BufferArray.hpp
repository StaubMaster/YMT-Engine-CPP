
#ifndef  INSTANCE_BASE_BUFFER_ARRAY
# define INSTANCE_BASE_BUFFER_ARRAY

# include "Graphics/Buffer/BaseBufferArray.hpp"

# include "OpenGL/openGL.h"
//# include <iostream>

template<
	typename MainDataType,
	typename MainBufferType,
	typename InstDataType,
	typename InstBufferType
>
class Instance_Base_BufferArray : public BaseBufferArray
{
	protected:
	private:
		MainBufferType * MainBuffer;
		InstBufferType * InstBuffer;
		unsigned int DrawMode;

	public:
		Instance_Base_BufferArray(
			MainBufferType * main_buffer,
			InstBufferType * inst_buffer,
			unsigned int draw_mode
		) : BaseBufferArray(),
			MainBuffer(main_buffer),
			InstBuffer(inst_buffer),
			DrawMode(draw_mode) { }

		~Instance_Base_BufferArray()
		{
			delete MainBuffer;
			delete InstBuffer;
		}

	public:
		void BindMain(const MainDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			Use();
			MainBuffer -> BindData(GL_ARRAY_BUFFER, buffer_index, sizeof(MainDataType) * count, data, GL_STATIC_DRAW);
			MainBuffer -> Count = count;
		}
		void BindInst(const InstDataType * data, unsigned int count, unsigned int buffer_index = 0)
		{
			Use();
			InstBuffer -> BindData(GL_ARRAY_BUFFER, buffer_index, sizeof(InstDataType) * count, data, GL_STREAM_DRAW);
			InstBuffer -> Count = count;
		}

	public:
		void Draw() override
		{
			Use();
			glDrawArraysInstanced(DrawMode, 0, MainBuffer -> Count, InstBuffer -> Count);
		}
};

#endif
