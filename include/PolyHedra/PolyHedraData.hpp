#ifndef POLYHEDRA_HPP
# define POLYHEDRA_HPP

# include "EditableArray.hpp"
# include "Abstract2D/Point2D.hpp"
# include "Abstract3D/Point3D.hpp"
# include "Abstract3D/Undex3D.hpp"

# include "BufferUni.hpp"

namespace YMT
{
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
		struct TexUndex
		{
			unsigned int Udx;
			Point2D Tex;

			public:
			TexUndex(unsigned int udx, float tex_x, float tex_y);
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



	private:
		void Edit_Face_Color(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int col);
		void Edit_Face3(TexUndex corn0, TexUndex corn1, TexUndex corn2);
		void Edit_Face4(TexUndex corn0, TexUndex corn1, TexUndex corn2, TexUndex corn3);
		void Edit_Trim();

	public:
		static PolyHedra * Cube(float scale = 1.0f);



	public:
		class ShaderInst;
		class BufferInst;

	private:
		RenderPoint3D * ToBufferData(int & count);

	public:
		void ToUni();
		void ToUni(PolyHedraBuffer & Buffer);
		void DrawUni();

		void ToInst();
		void ToInst(BufferInst & Buffer);
		void DrawInst();
};
};

#endif