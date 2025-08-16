#ifndef POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "EditableArray.hpp"
# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"

class PolyHedra
{
	public:
		struct PosTex
		{
			public:
				Point3D	Pos;
				Point2D	Tex;
		};

	public:
		EditableArray<PosTex>	Corns;
		EditableArray<Undex3D>	Faces;

	private:
		PolyHedra();
		~PolyHedra();

	public:
		static PolyHedra * Cube(float scale);
};

#endif