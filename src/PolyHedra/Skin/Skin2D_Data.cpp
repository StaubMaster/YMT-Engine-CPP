#include "PolyHedra/Skin/Skin2D_Data.hpp"



Skin2DFaceCorner::Skin2DFaceCorner() { }
Skin2DFaceCorner::Skin2DFaceCorner(Point2D tex) : Tex(tex) { }

Skin2DFace::Skin2DFace() { }
Skin2DFace::Skin2DFace(Skin2DFaceCorner corn0, Skin2DFaceCorner corn1, Skin2DFaceCorner corn2) : Corner0(corn0), Corner1(corn1), Corner2(corn2) { }
