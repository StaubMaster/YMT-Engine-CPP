#include "PolyHedra/Template.hpp"
#include "PolyHedra/Data.hpp"

#include "DataStruct/Point3D.hpp"



YMT::PolyHedra::Template::Template(YMT::PolyHedra & referance) :
	Referance(referance)
{ }



void YMT::PolyHedra::Template::Done()
{
	Referance.Corners.Trim();
	Referance.Faces.Trim();

	Calc_Face_Normals();
	Calc_Corn_Normals();
}



void YMT::PolyHedra::Template::Calc_Face_Normals()
{
	for (unsigned int i = 0; i < Referance.Faces.Count(); i++)
	{
		Face & face = Referance.Faces[i];
		if (face.Corner0.Udx < Referance.Corners.Count() &&
			face.Corner1.Udx < Referance.Corners.Count() &&
			face.Corner2.Udx < Referance.Corners.Count())
		{
			const Point3D & cornerX = Referance.Corners[face.Corner0.Udx].Position;
			const Point3D & cornerY = Referance.Corners[face.Corner1.Udx].Position;
			const Point3D & cornerZ = Referance.Corners[face.Corner2.Udx].Position;
			face.Normal = Point3D::cross(cornerY - cornerX, cornerZ - cornerX).normalize();
		}
		else
		{
			face.Normal = Point3D();
		}
	}
}
void YMT::PolyHedra::Template::Calc_Corn_Normals()
{
	for (unsigned int i = 0; i < Referance.Corners.Count(); i++)
	{
		Point3D normal_sum(0, 0, 0);
		for (unsigned int j = 0; j < Referance.Faces.Count(); j++)
		{
			const Face & face = Referance.Faces[j];
			if (face.Corner0.Udx == i ||
				face.Corner1.Udx == i ||
				face.Corner2.Udx == i
			)
			{
				normal_sum = normal_sum + face.Normal;
			}
		}
		Referance.Corners[i].Normal = normal_sum.normalize();
	}
}



void YMT::PolyHedra::Template::Insert_Corn(Corner corn)
{
	Referance.Corners.Insert(corn);
}
void YMT::PolyHedra::Template::Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2)
{
	Referance.Faces.Insert(Face(corn0, corn1, corn2));
}
void YMT::PolyHedra::Template::Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}


