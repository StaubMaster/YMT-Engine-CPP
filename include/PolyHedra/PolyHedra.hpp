#ifndef  POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "Miscellaneous/ContainerDynamic.hpp"
# include <string>

struct PolyHedra_MainData;

class PolyHedra_SkinBase;

struct Point2D;

class Image;

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
		PolyHedra_SkinBase *		Skin;

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
		static PolyHedra * Cube(float scale = 1.0f);
		static PolyHedra * ConeC(int segments, float width = 1.0f, float height = 1.0f);
		static PolyHedra * FullTexture(Image * img, float scale = 1.0f);

	public:
		PolyHedra_MainData * ToMainData(int & count);
	public:
		std::string ToInfo() const;
};
};

#endif