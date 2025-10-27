#ifndef  POLYHEDRA_SKIN_2DA_HPP
# define POLYHEDRA_SKIN_2DA_HPP

# include "PolyHedra_SkinBase.hpp"
# include "Texture2DArray.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"
# include <string>

# include "DataStruct/Point2D.hpp"
# include "DataStruct/Point3D.hpp"

class PolyHedra_Skin2DA : public PolyHedra_SkinBase
{
	public:
		struct Corner
		{
			Point3D	Normal;
			Corner();
		};
		struct FaceCorner
		{
			Point2D	Tex;
			FaceCorner();
			//FaceCorner(Point2D tex);
			FaceCorner(float tex_x, float tex_y);
		};
		struct Face
		{
			FaceCorner	Corner0;
			FaceCorner	Corner1;
			FaceCorner	Corner2;
			Point3D	Normal;
			Face();
			Face(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		};

	private:
	public:
		ContainerDynamic<Corner>	Corners;
		ContainerDynamic<Face>		Faces;

	public:
		PolyHedra_Skin2DA(YMT::PolyHedra & polyhedra);
		~PolyHedra_Skin2DA();

	public:
		void Done();
		void Calc_Face_Normals();
		void Calc_Corn_Normals();

		void Insert_Corn(Corner corn);
		void Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2);
		void Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3);
};

#endif
