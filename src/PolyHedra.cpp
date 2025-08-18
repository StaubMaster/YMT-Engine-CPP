#include "PolyHedra.hpp"

PolyHedra::PolyHedra() :
	Corners(),
	FaceIndexes(),
	FaceTextures()
{
	Buffer = NULL;
}
PolyHedra::~PolyHedra()
{
	if (Buffer != NULL)
	{
		delete Buffer;
	}
}



void PolyHedra::ToBuffer()
{
	Buffer = new PolyHedraBuffer();

	int count = FaceIndexes.Length * 3;
	RenderPoint3D data[count];

	for (unsigned int i = 0; i < FaceIndexes.Length; i++)
	{
		Undex3D face = FaceIndexes[i];
		FaceTex texs = FaceTextures[i];

		int c = i * 3;
		data[c + 0].Position = Corners[face.X];
		data[c + 1].Position = Corners[face.Y];
		data[c + 2].Position = Corners[face.Z];

		data[c + 0].Normal = texs.X;
		data[c + 1].Normal = texs.Y;
		data[c + 2].Normal = texs.Z;

		data[c + 0].Texture = Point2D();
		data[c + 1].Texture = Point2D();
		data[c + 2].Texture = Point2D();
	}

	Buffer -> Data(count, data);
}
void PolyHedra::Draw()
{
	if (Buffer != NULL)
	{
		Buffer -> Draw();
	}
}



void PolyHedra::Edit_Trim()
{
	Corners.Trim();
	FaceIndexes.Trim();
	FaceTextures.Trim();
}
void PolyHedra::Edit_Face_Color(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int col)
{
	FaceIndexes.Insert(Undex3D(idx0, idx1, idx2));

	Point3D color;
	color.X = ((col >> 16) & 0xFF) / 255.0f;
	color.Y = ((col >> 8) & 0xFF) / 255.0f;
	color.Z = ((col >> 0) & 0xFF) / 255.0f;

	FaceTex texs;
	texs.X = color;
	texs.Y = color;
	texs.Z = color;
	FaceTextures.Insert(texs);
}

PolyHedra::TexUndex::TexUndex(unsigned int udx, float tex_x, float tex_y) :
	Udx(udx), Tex(tex_x, tex_y) { }

void PolyHedra::Edit_Face3(TexUndex corn0, TexUndex corn1, TexUndex corn2)
{
	FaceIndexes.Insert(Undex3D(corn0.Udx, corn1.Udx, corn2.Udx));

	FaceTex texs;
	texs.X = Point3D(corn0.Tex.X, corn0.Tex.Y, 0);
	texs.Y = Point3D(corn1.Tex.X, corn1.Tex.Y, 0);
	texs.Z = Point3D(corn2.Tex.X, corn2.Tex.Y, 0);
	FaceTextures.Insert(texs);
}
void PolyHedra::Edit_Face4(TexUndex corn0, TexUndex corn1, TexUndex corn2, TexUndex corn3)
{
	Edit_Face3(corn0, corn1, corn2);
	Edit_Face3(corn2, corn1, corn3);
}



PolyHedra * PolyHedra::Cube(float scale)
{
	PolyHedra * temp = new PolyHedra();

	temp -> Corners.Insert(Point3D(-scale, -scale, -scale));
	temp -> Corners.Insert(Point3D(+scale, -scale, -scale));
	temp -> Corners.Insert(Point3D(-scale, +scale, -scale));
	temp -> Corners.Insert(Point3D(+scale, +scale, -scale));
	temp -> Corners.Insert(Point3D(-scale, -scale, +scale));
	temp -> Corners.Insert(Point3D(+scale, -scale, +scale));
	temp -> Corners.Insert(Point3D(-scale, +scale, +scale));
	temp -> Corners.Insert(Point3D(+scale, +scale, +scale));

	temp -> Edit_Face4(
		TexUndex(0b000, 0.00f, 0.00f),
		TexUndex(0b010, 1.00f, 0.00f),
		TexUndex(0b001, 0.00f, 1.00f),
		TexUndex(0b011, 1.00f, 1.00f)
	);
	temp -> Edit_Face4(
		TexUndex(0b000, 0.00f, 0.00f),
		TexUndex(0b100, 1.00f, 0.00f),
		TexUndex(0b010, 0.00f, 1.00f),
		TexUndex(0b110, 1.00f, 1.00f)
	);
	temp -> Edit_Face4(
		TexUndex(0b000, 0.00f, 0.00f),
		TexUndex(0b001, 1.00f, 0.00f),
		TexUndex(0b100, 0.00f, 1.00f),
		TexUndex(0b101, 1.00f, 1.00f)
	);



	temp -> Edit_Face4(
		TexUndex(0b111, 0.00f, 0.00f),
		TexUndex(0b110, 0.00f, 1.00f),
		TexUndex(0b101, 1.00f, 0.00f),
		TexUndex(0b100, 1.00f, 1.00f)
	);
	temp -> Edit_Face4(
		TexUndex(0b111, 0.00f, 0.00f),
		TexUndex(0b101, 0.00f, 1.00f),
		TexUndex(0b011, 1.00f, 0.00f),
		TexUndex(0b001, 1.00f, 1.00f)
	);
	temp -> Edit_Face4(
		TexUndex(0b111, 0.00f, 0.00f),
		TexUndex(0b011, 0.00f, 1.00f),
		TexUndex(0b110, 1.00f, 0.00f),
		TexUndex(0b010, 1.00f, 1.00f)
	);

	temp -> Edit_Trim();
	return temp;
}
