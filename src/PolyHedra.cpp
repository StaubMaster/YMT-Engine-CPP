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

	temp -> Edit_Face_Color(0b000, 0b010, 0b001, 0xFF0000);
	temp -> Edit_Face_Color(0b001, 0b010, 0b011, 0xFF0000);

	temp -> Edit_Face_Color(0b000, 0b100, 0b010, 0x00FF00);
	temp -> Edit_Face_Color(0b010, 0b100, 0b110, 0x00FF00);

	temp -> Edit_Face_Color(0b000, 0b001, 0b100, 0x0000FF);
	temp -> Edit_Face_Color(0b100, 0b001, 0b101, 0x0000FF);

	temp -> Edit_Face_Color(0b110, 0b101, 0b111, 0xFF0000);
	temp -> Edit_Face_Color(0b100, 0b101, 0b110, 0xFF0000);

	temp -> Edit_Face_Color(0b101, 0b011, 0b111, 0x00FF00);
	temp -> Edit_Face_Color(0b001, 0b011, 0b101, 0x00FF00);

	temp -> Edit_Face_Color(0b011, 0b110, 0b111, 0x0000FF);
	temp -> Edit_Face_Color(0b010, 0b110, 0b011, 0x0000FF);

	temp -> Edit_Trim();
	return temp;
}
