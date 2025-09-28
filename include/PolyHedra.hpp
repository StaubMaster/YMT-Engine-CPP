#ifndef POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Data/2D/Point2D.hpp"
# include "Data/3D/Point3D.hpp"
# include "Data/3D/Undex3D.hpp"

# include "Graphics/PH/PolyHedra_MainData.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include <vector>

namespace YMT
{
class PolyHedra
{
	private:
		struct Corner
		{
			Point3D	Position;
			Point3D	Normal;

			Corner();
			Corner(Point3D pos);
		};
		struct FaceCorner
		{
			unsigned int Udx;
			Point2D Tex;

			FaceCorner();
			FaceCorner(unsigned int udx, float tex_x, float tex_y);
		};
		struct Face
		{
			FaceCorner Corner0;
			FaceCorner Corner1;
			FaceCorner Corner2;
			Point3D Normal;

			Face();
			Face(FaceCorner c0, FaceCorner c1, FaceCorner c2);
		};

	private:
		ContainerDynamic<Corner>	Corners;
		ContainerDynamic<Face>		Faces;

	private:
		PolyHedra();
	public:
		~PolyHedra();

	public:
		static PolyHedra * FullTexture(float scale = 1.0f);
		static PolyHedra * Cube(float scale = 1.0f);
		static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);

	private:
		void Done();
		void Calc_Face_Normals();
		void Calc_Corn_Normals();

		void Insert_Corn(Corner corn);
		void Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		void Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3);

	public:
		PolyHedra_MainData * ToMainData(int & count);
};
};

#endif