#include "PolyHedra/Skin/Skin2DA.hpp"
#include "PolyHedra/PolyHedra.hpp"



PolyHedra_Skin2DA::Corner::Corner() { }

PolyHedra_Skin2DA::FaceCorner::FaceCorner() { }
PolyHedra_Skin2DA::FaceCorner::FaceCorner(float tex_x, float tex_y) : Tex(tex_x, tex_y) { }

PolyHedra_Skin2DA::Face::Face() { }
PolyHedra_Skin2DA::Face::Face(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2) : Corner0(corn0), Corner1(corn1), Corner2(corn2) { }



PolyHedra_Skin2DA::PolyHedra_Skin2DA(YMT::PolyHedra & polyhedra) : PolyHedra_SkinBase(polyhedra) { }
PolyHedra_Skin2DA::~PolyHedra_Skin2DA() { }



void PolyHedra_Skin2DA::Done()
{
	Corners.Trim();
	Faces.Trim();
}

void PolyHedra_Skin2DA::Insert_Corn(Corner corn)
{
	Corners.Insert(corn);
}
void PolyHedra_Skin2DA::Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2)
{
	Faces.Insert(Face(corn0, corn1, corn2));
}
void PolyHedra_Skin2DA::Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}
