
#ifndef POLYHEDRA_3D_BUFFER
# define POLYHEDRA_3D_BUFFER

# include <iostream>
# include "OpenGL/openGL.h"

# include "PolyHedra_MainData.hpp"
# include "PolyHedra_3D_InstData.hpp"

# include "Abstract.hpp"

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
