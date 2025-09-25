#include "PolyHedra.hpp"



YMT::PolyHedra::PolyHedra() :
	Corners(),
	FaceIndexes(),
	FaceTextures()
{
	Buffer = NULL;
}
YMT::PolyHedra::~PolyHedra()
{
	if (Buffer != NULL)
	{
		delete Buffer;
	}
}





void YMT::PolyHedra::Edit_Trim()
{
	Corners.Trim();
	FaceIndexes.Trim();
	FaceTextures.Trim();
}
/*void YMT::PolyHedra::Edit_Face_Color(unsigned int idx0, unsigned int idx1, unsigned int idx2, unsigned int col)
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
}*/

YMT::PolyHedra::TexUndex::TexUndex(unsigned int udx, float tex_x, float tex_y) :
	Udx(udx), Tex(tex_x, tex_y) { }

void YMT::PolyHedra::Edit_Face3(TexUndex corn0, TexUndex corn1, TexUndex corn2)
{
	FaceIndexes.Insert(Undex3D(corn0.Udx, corn1.Udx, corn2.Udx));

	FaceTex texs;
	texs.X = Point2D(corn0.Tex.X, corn0.Tex.Y);
	texs.Y = Point2D(corn1.Tex.X, corn1.Tex.Y);
	texs.Z = Point2D(corn2.Tex.X, corn2.Tex.Y);
	FaceTextures.Insert(texs);
}
void YMT::PolyHedra::Edit_Face4(TexUndex corn0, TexUndex corn1, TexUndex corn2, TexUndex corn3)
{
	Edit_Face3(corn0, corn1, corn2);
	Edit_Face3(corn2, corn1, corn3);
}



YMT::PolyHedra * YMT::PolyHedra::Cube(float scale)
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
		TexUndex(0b010, 0.00f, 0.50f),
		TexUndex(0b001, 0.25f, 0.00f),
		TexUndex(0b011, 0.25f, 0.50f)
	);
	temp -> Edit_Face4(
		TexUndex(0b000, 0.25f, 0.00f),
		TexUndex(0b100, 0.25f, 0.50f),
		TexUndex(0b010, 0.50f, 0.00f),
		TexUndex(0b110, 0.50f, 0.50f)
	);
	temp -> Edit_Face4(
		TexUndex(0b000, 0.50f, 0.00f),
		TexUndex(0b001, 0.50f, 0.50f),
		TexUndex(0b100, 0.75f, 0.00f),
		TexUndex(0b101, 0.75f, 0.50f)
	);



	temp -> Edit_Face4(
		TexUndex(0b111, 0.25f, 1.00f),
		TexUndex(0b110, 0.00f, 1.00f),
		TexUndex(0b101, 0.25f, 0.50f),
		TexUndex(0b100, 0.00f, 0.50f)
	);
	temp -> Edit_Face4(
		TexUndex(0b111, 0.50f, 1.00f),
		TexUndex(0b101, 0.25f, 1.00f),
		TexUndex(0b011, 0.50f, 0.50f),
		TexUndex(0b001, 0.25f, 0.50f)
	);
	temp -> Edit_Face4(
		TexUndex(0b111, 0.75f, 1.00f),
		TexUndex(0b011, 0.50f, 1.00f),
		TexUndex(0b110, 0.75f, 0.50f),
		TexUndex(0b010, 0.50f, 0.50f)
	);

	temp -> Edit_Trim();
	return temp;
}







PolyHedra_MainData * YMT::PolyHedra::ToMainData(int & count)
{
	count = FaceIndexes.Length * 3;
	PolyHedra_MainData * data = new PolyHedra_MainData[count];

	for (unsigned int i = 0; i < FaceIndexes.Length; i++)
	{
		Undex3D face = FaceIndexes[i];
		FaceTex texs = FaceTextures[i];

		const Point3D & cornerX = Corners[face.X];
		const Point3D & cornerY = Corners[face.Y];
		const Point3D & cornerZ = Corners[face.Z];
		Point3D normal = Point3D::cross(cornerY - cornerX, cornerZ - cornerX);

		int c = i * 3;
		data[c + 0].Position = cornerX;
		data[c + 1].Position = cornerY;
		data[c + 2].Position = cornerZ;

		data[c + 0].Normal = normal;
		data[c + 1].Normal = normal;
		data[c + 2].Normal = normal;

		data[c + 0].Texture = texs.X;
		data[c + 1].Texture = texs.Y;
		data[c + 2].Texture = texs.Z;
	}

	return data;
}



void YMT::PolyHedra::ToUni()
{
	Buffer = new PolyHedraBuffer();

	int count;
	PolyHedra_MainData * data;
	data = ToMainData(count);
	Buffer -> Data(count, data);
	delete [] data;
}
void YMT::PolyHedra::DrawUni()
{
	if (Buffer != NULL)
	{
		Buffer -> Draw();
	}
}



void YMT::PolyHedra::ToInst(BufferInst & Buffer)
{
	int count;
	PolyHedra_MainData * data;
	data = ToMainData(count);
	Buffer.DataPolyHedra(count, data);
	delete [] data;
}
