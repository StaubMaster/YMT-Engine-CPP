#ifndef  TEXTURE_2D_FACE_HPP
# define TEXTURE_2D_FACE_HPP

# include "DataStruct/Point2D.hpp"

struct Skin2DCorner
{

};

struct Skin2DFaceCorner
{
	Point2D	Tex;

	Skin2DFaceCorner();
	Skin2DFaceCorner(Point2D tex);
};

struct Skin2DFace
{
	Skin2DFaceCorner	Corner0;
	Skin2DFaceCorner	Corner1;
	Skin2DFaceCorner	Corner2;

	Skin2DFace();
	Skin2DFace(Skin2DFaceCorner corn0, Skin2DFaceCorner corn1, Skin2DFaceCorner corn2);
};

#endif
