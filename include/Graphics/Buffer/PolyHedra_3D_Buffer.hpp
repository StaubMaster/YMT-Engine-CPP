
#ifndef POLYHEDRA_3D_BUFFER
# define POLYHEDRA_3D_BUFFER

# include <iostream>
# include "OpenGL/openGL.h"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_3D_InstData.hpp"

# include "Abstract.hpp"

/*
	storing the Instance Data here is bad for CL
	make this _BufferGL
	no
	leave this as _Buffer because thats what this is
	but what to name the one that has _Buffer with extra data ?

	just looked into things
	I could make EntryContainer with an allocator
	and them make an allocator that allocates on the GPU
	using BufferData() with NULL and MapBuffer()
	but that is some advanced stuff
	that could also be used to never allocate on the CPU at all
	that is what is wanted in particle system
	but that is also a static size
	this is Dynamic size

	name:
		_Manager ?
		but Manager is also supposed to have Shader
		should each Buffer have a Referance to what Shader to use ?
		changing Shader is apparently slow
		so doing that would be bad
		also _Manager would make more sense for the collection of these with a collection of Shaders
		_Instances ?
		as a placeholder
*/

class PolyHedra_3D_Buffer
{
	private:
		unsigned int BufferArray;

		unsigned int MainBuffer;
		unsigned int MainCount;

		unsigned int InstBuffer;
		unsigned int InstCount;

		unsigned int TextureArray;

	public:
		PolyHedra_3D_Buffer();
		~PolyHedra_3D_Buffer();

	public:
		void BindMain(const PolyHedra_MainData * data, unsigned int count);
		void BindInst(const PolyHedra_3D_InstData * data, unsigned int count);
		//void BindTex(const  * data, unsigned int count);

	public:
		void Draw();
};

#endif
