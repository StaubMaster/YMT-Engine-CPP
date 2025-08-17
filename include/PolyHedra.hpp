#ifndef POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "EditableArray.hpp"
# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"

# include "PolyHedraBuffer.hpp"

/*
	should everything be in one ?
	or should it be seperate ?
	i think seperate might me slightly more memory efficient ?
	and the Render Data only needs to be made once ?

	should PolyHedra hold its buffer
	there is the edge case of doing math with a purely abstract PolyHeadra
	that is not drawn
	but I cant think of a case where I need that currently
*/

class PolyHedra
{
	private:
		struct FaceTex
		{
			//	X Y Z has nothing to do with Direction
			//	it is just to be the same as with Undex3D
			Point3D	X;
			Point3D	Y;
			Point3D	Z;
			//	3D for Color for Testing
		};

	private:
		EditableArray<Point3D>	Corners;
		EditableArray<Undex3D>	FaceIndexes;
		EditableArray<FaceTex>	FaceTextures;
		PolyHedraBuffer * Buffer;

	private:
		PolyHedra();
	public:
		~PolyHedra();

	public:
		void ToBuffer();
		void Draw();

	private:
		void Edit_Face_Color(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int col);
		void Edit_Trim();

	public:
		static PolyHedra * Cube(float scale = 1.0f);
};

#endif