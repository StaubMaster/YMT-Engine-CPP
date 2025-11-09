
#ifndef POLYHEDRA_3D_Instances
# define POLYHEDRA_3D_Instances

# include "PolyHedra/PolyHedra.hpp"
# include "Miscellaneous/EntryContainer/EntryContainerDynamic.hpp"

# include "PolyHedra_3D_BufferArray.hpp"

# include "OpenGL/openGL.h"
# include <iostream>

namespace Texture
{
	class Base;
};

class PolyHedra_3D_Instances
{
	public:
		PolyHedra_3D_BufferArray Buffer;
		//YMT::PolyHedra * Main;
		Texture::Base * Texture;
		EntryContainerDynamic<Simple3D_InstData> Instances;

	public:
		PolyHedra_3D_Instances(YMT::PolyHedra * polyhedra);
		~PolyHedra_3D_Instances();

	public:
		EntryContainerDynamic<Simple3D_InstData>::Entry * Alloc(int size);
		/*
			make a Wrapper for these Entrys ?
			I'm already planing on making an Array of these
			and then have an Entry Wrapper for those
		*/

	public:
		PolyHedra_3D_Instances & Update();
		PolyHedra_3D_Instances & Draw();
};

#endif
