#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Graphics/PH/PolyHedra_MainData.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

namespace YMT
{

class PolyHedra
{
	private:
		struct Corner;
		struct FaceCorner;
		struct Face;

	private:
		ContainerDynamic<Corner>	Corners;
		ContainerDynamic<Face>		Faces;

	public:
		bool UseCornerNormals;

	private:
		PolyHedra();
	public:
		~PolyHedra();

	private:
		void Done();
		void Calc_Face_Normals();
		void Calc_Corn_Normals();

		void Insert_Corn(Corner corn);
		void Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		void Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3);

	public:
		static PolyHedra * FullTexture(float scale = 1.0f);
		static PolyHedra * Cube(float scale = 1.0f);
		static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);

	public:
		PolyHedra_MainData * ToMainData(int & count);
};
};

#endif