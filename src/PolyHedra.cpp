#include "PolyHedra.hpp"
#include "PolyHedraData.hpp"

#include "DataStruct/Angle3D.hpp"

#define TAU 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413



YMT::PolyHedra::PolyHedra() :
	Corners(), Faces()
{
	UseCornerNormals = false;
}
YMT::PolyHedra::~PolyHedra()
{

}





void YMT::PolyHedra::Done()
{
	Corners.Trim();
	Faces.Trim();

	Calc_Face_Normals();
	Calc_Corn_Normals();
}
void YMT::PolyHedra::Calc_Face_Normals()
{
	for (unsigned int i = 0; i < Faces.Count(); i++)
	{
		Face & face = Faces[i];
		const Point3D & cornerX = Corners[face.Corner0.Udx].Position;
		const Point3D & cornerY = Corners[face.Corner1.Udx].Position;
		const Point3D & cornerZ = Corners[face.Corner2.Udx].Position;
		face.Normal = Point3D::cross(cornerY - cornerX, cornerZ - cornerX);
	}
}
void YMT::PolyHedra::Calc_Corn_Normals()
{
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		Point3D normal_sum(0, 0, 0);
		for (unsigned int j = 0; j < Faces.Count(); j++)
		{
			const Face & face = Faces[j];
			if (
				face.Corner0.Udx == i ||
				face.Corner1.Udx == i ||
				face.Corner2.Udx == i
			)
			{
				normal_sum = normal_sum + face.Normal;
			}
		}
		Corners[i].Normal = normal_sum.normalize();
	}
}

void YMT::PolyHedra::Insert_Face3(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2)
{
	Faces.Insert(Face(corn0, corn1, corn2));
}
void YMT::PolyHedra::Insert_Face4(FaceCorner corn0, FaceCorner corn1, FaceCorner corn2, FaceCorner corn3)
{
	Insert_Face3(corn0, corn1, corn2);
	Insert_Face3(corn2, corn1, corn3);
}



YMT::PolyHedra * YMT::PolyHedra::FullTexture(float scale)
{
	PolyHedra * temp = new PolyHedra();

	temp -> Corners.Insert(Point3D(-scale, -scale, 0));
	temp -> Corners.Insert(Point3D(-scale, +scale, 0));
	temp -> Corners.Insert(Point3D(+scale, -scale, 0));
	temp -> Corners.Insert(Point3D(+scale, +scale, 0));

	temp -> Insert_Face4(
		FaceCorner(0, 0.0f, 1.0f),
		FaceCorner(1, 0.0f, 0.0f),
		FaceCorner(2, 1.0f, 1.0f),
		FaceCorner(3, 1.0f, 0.0f)
	);

	temp -> Done();
	return temp;
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

	temp -> Insert_Face4(
		FaceCorner(0b000, 0.00f, 0.00f),
		FaceCorner(0b010, 0.00f, 0.50f),
		FaceCorner(0b001, 0.25f, 0.00f),
		FaceCorner(0b011, 0.25f, 0.50f)
	);
	temp -> Insert_Face4(
		FaceCorner(0b000, 0.25f, 0.00f),
		FaceCorner(0b100, 0.25f, 0.50f),
		FaceCorner(0b010, 0.50f, 0.00f),
		FaceCorner(0b110, 0.50f, 0.50f)
	);
	temp -> Insert_Face4(
		FaceCorner(0b000, 0.50f, 0.00f),
		FaceCorner(0b001, 0.50f, 0.50f),
		FaceCorner(0b100, 0.75f, 0.00f),
		FaceCorner(0b101, 0.75f, 0.50f)
	);



	temp -> Insert_Face4(
		FaceCorner(0b111, 0.25f, 1.00f),
		FaceCorner(0b110, 0.00f, 1.00f),
		FaceCorner(0b101, 0.25f, 0.50f),
		FaceCorner(0b100, 0.00f, 0.50f)
	);
	temp -> Insert_Face4(
		FaceCorner(0b111, 0.50f, 1.00f),
		FaceCorner(0b101, 0.25f, 1.00f),
		FaceCorner(0b011, 0.50f, 0.50f),
		FaceCorner(0b001, 0.25f, 0.50f)
	);
	temp -> Insert_Face4(
		FaceCorner(0b111, 0.75f, 1.00f),
		FaceCorner(0b011, 0.50f, 1.00f),
		FaceCorner(0b110, 0.75f, 0.50f),
		FaceCorner(0b010, 0.50f, 0.50f)
	);

	temp -> Done();
	return temp;
}
YMT::PolyHedra * YMT::PolyHedra::ConeC(int segments, float width, float height)
{
	PolyHedra * temp = new PolyHedra();

	Angle3D angle;

	int idx_frst = temp -> Corners.Count();
	temp -> Corners.Insert(Point3D(0, 0, +height));
	for (int i = 0; i < segments; i++)
	{
		angle.ChangeZ((TAU * i) / segments);
		temp -> Corners.Insert(angle.rotate_fore(Point3D(0, +width, -height)));
	}
	int idx_last = temp -> Corners.Count();
	temp -> Corners.Insert(Point3D(0, 0, -height));

	for (int i = 0; i < segments; i++)
	{
		float tex0 = (0.0f + i) / segments;
		float tex1 = (1.0f + i) / segments;
		float texM = (0.5f + i) / segments;

		int idx_curr = ((i + 0) % segments) + 1;
		int idx_next = ((i + 1) % segments) + 1;

		temp -> Insert_Face4(
			FaceCorner(idx_frst, texM, 0.0f),
			FaceCorner(idx_next, tex1, 1.0f),
			FaceCorner(idx_curr, tex0, 1.0f),
			FaceCorner(idx_last, texM, 0.0f)
		);
	}

	temp -> Done();
	return temp;
}







PolyHedra_MainData * YMT::PolyHedra::ToMainData(int & count)
{
	count = Faces.Count() * 3;
	PolyHedra_MainData * data = new PolyHedra_MainData[count];

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		const Face & face = Faces[f];
		const Corner & cornerX = Corners[face.Corner0.Udx];
		const Corner & cornerY = Corners[face.Corner1.Udx];
		const Corner & cornerZ = Corners[face.Corner2.Udx];

		int c = f * 3;
		data[c + 0].Position = cornerX.Position;
		data[c + 1].Position = cornerY.Position;
		data[c + 2].Position = cornerZ.Position;

		if (!UseCornerNormals)
		{
			data[c + 0].Normal = face.Normal;
			data[c + 1].Normal = face.Normal;
			data[c + 2].Normal = face.Normal;
		}
		else
		{
			data[c + 0].Normal = cornerX.Normal;
			data[c + 1].Normal = cornerY.Normal;
			data[c + 2].Normal = cornerZ.Normal;
		}

		data[c + 0].Texture = face.Corner0.Tex;
		data[c + 1].Texture = face.Corner1.Tex;
		data[c + 2].Texture = face.Corner2.Tex;
	}

	return data;
}
