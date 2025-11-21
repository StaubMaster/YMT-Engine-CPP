#ifndef  POLYHEDRA_TEMPLATE_HPP
# define POLYHEDRA_TEMPLATE_HPP

# include "PolyHedra.hpp"

namespace YMT
{
	struct PolyHedra::Template
	{
		PolyHedra &	Referance;

		Template(PolyHedra & referance);

		void Done();

		void Calc_Face_Normals();
		void Calc_Corn_Normals();

		void Insert_Corn(Corner corn);
		void Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		void Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3);
	};
};

#endif
