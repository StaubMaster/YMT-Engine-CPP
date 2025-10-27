#ifndef  POLYHEDRA_DATA_HPP
# define POLYHEDRA_DATA_HPP

# include "PolyHedra.hpp"

# include "DataStruct/Point2D.hpp"
# include "DataStruct/Point3D.hpp"

namespace YMT
{
	struct PolyHedra::Corner
	{
		Point3D	Position;
		Corner();
		Corner(Point3D pos);
	};
	struct PolyHedra::FaceCorner
	{
		unsigned int Udx;
		FaceCorner();
		FaceCorner(unsigned int udx);
	};
	struct PolyHedra::Face
	{
		FaceCorner Corner0;
		FaceCorner Corner1;
		FaceCorner Corner2;
		Face();
		Face(FaceCorner c0, FaceCorner c1, FaceCorner c2);
	};
};

#endif
