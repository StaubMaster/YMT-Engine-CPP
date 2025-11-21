#ifndef  POLYHEDRA_GENERATE_HPP
# define POLYHEDRA_GENERATE_HPP

# include "PolyHedra.hpp"

namespace YMT
{
	struct PolyHedra::Generate
	{
		Generate() = delete;

		static PolyHedra * Cube(float scale = 1.0f);
		static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);
		static PolyHedra * FullTexture(Image * img, float scale = 1.0f);
	};
};

#endif
