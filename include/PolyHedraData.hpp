#ifndef  POLYHEDRA_DATA_HPP
# define POLYHEDRA_DATA_HPP

# include "PolyHedra.hpp"

# include "Data/2D/Point2D.hpp"
# include "Data/3D/Point3D.hpp"

namespace YMT
{
	struct PolyHedra::Corner
	{
		Point3D	Position;
		Point3D	Normal;
		Corner();
		Corner(Point3D pos);
	};
	struct PolyHedra::FaceCorner
	{
		unsigned int Udx;
		Point2D Tex;
		FaceCorner();
		FaceCorner(unsigned int udx, float tex_x, float tex_y);
	};
	struct PolyHedra::Face
	{
		FaceCorner Corner0;
		FaceCorner Corner1;
		FaceCorner Corner2;
		Point3D Normal;
		Face();
		Face(FaceCorner c0, FaceCorner c1, FaceCorner c2);
	};
};

#endif
