#ifndef POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "EditableArray.hpp"
# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"

# include "Graphics/Buffer/PolyHedra_MainData.hpp"

namespace YMT
{
class PolyHedra
{
	private:
		struct FaceTex
		{
			Point2D	X;
			Point2D	Y;
			Point2D	Z;
		};
		struct TexUndex
		{
			unsigned int Udx;
			Point2D Tex;

			TexUndex(unsigned int udx, float tex_x, float tex_y);
		};

	private:
		EditableArray<Point3D>	Corners;
		EditableArray<Undex3D>	FaceIndexes;
		EditableArray<FaceTex>	FaceTextures;



	private:
		PolyHedra();
	public:
		~PolyHedra();



	private:
		//void Edit_Face_Color(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int col);
		void Edit_Face3(TexUndex corn0, TexUndex corn1, TexUndex corn2);
		void Edit_Face4(TexUndex corn0, TexUndex corn1, TexUndex corn2, TexUndex corn3);
		void Edit_Trim();

	public:
		static PolyHedra * Cube(float scale = 1.0f);



	public:
		class ShaderInst;

	public:
		/*
			I dont like the data and the Length being seperate
			I also dont like worrying about deleting thins
			but how else would I do that
			since returning something here creates a new object ?
			where I then have to eighter
				copy all the data
			or
				copy the pointer over
				and delete the old one
		*/
		PolyHedra_MainData * ToMainData(int & count);
};
};

#endif