#include "PolyHedra/PolyHedra.hpp"
#include "PolyHedra/PolyHedraData.hpp"

#include "PolyHedra/Skin/Skin2DA.hpp"

#include "DataStruct/Main/PolyHedra/PolyHedra_MainData.hpp"

#include "DataStruct/Angle3D.hpp"
#include "DataStruct/AxisBox3D.hpp"

#include "Graphics/Texture/Generate.hpp"
#include "Format/Image.hpp"

#include "FileContext.hpp"

#include <sstream>

#include "DataShow.hpp"



YMT::PolyHedra::PolyHedra() :
	Corners(), Faces(),
	File(NULL),
	Skin(NULL)
{
	UseCornerNormals = false;
}
YMT::PolyHedra::~PolyHedra()
{
	delete File;
	delete Skin;
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
		if (face.Corner0.Udx < Corners.Count() &&
			face.Corner1.Udx < Corners.Count() &&
			face.Corner2.Udx < Corners.Count())
		{
			const Point3D & cornerX = Corners[face.Corner0.Udx].Position;
			const Point3D & cornerY = Corners[face.Corner1.Udx].Position;
			const Point3D & cornerZ = Corners[face.Corner2.Udx].Position;
			face.Normal = Point3D::cross(cornerY - cornerX, cornerZ - cornerX).normalize();
		}
		else
		{
			face.Normal = Point3D();
		}
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
			if (face.Corner0.Udx == i ||
				face.Corner1.Udx == i ||
				face.Corner2.Udx == i
			)
			{
				normal_sum = normal_sum + face.Normal;
				//std::cout << "Normal add: " << face.Normal << "\n";
			}
		}
		//std::cout << "Normal: " << normal_sum << "\n";
		Corners[i].Normal = normal_sum.normalize();
	}
}

void YMT::PolyHedra::Insert_Corn(Corner corn)
{
	Corners.Insert(corn);
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



YMT::PolyHedra * YMT::PolyHedra::Cube(float scale)
{
	PolyHedra * temp = new PolyHedra();

	temp -> Insert_Corn(Point3D(-scale, -scale, -scale));
	temp -> Insert_Corn(Point3D(+scale, -scale, -scale));
	temp -> Insert_Corn(Point3D(-scale, +scale, -scale));
	temp -> Insert_Corn(Point3D(+scale, +scale, -scale));
	temp -> Insert_Corn(Point3D(-scale, -scale, +scale));
	temp -> Insert_Corn(Point3D(+scale, -scale, +scale));
	temp -> Insert_Corn(Point3D(-scale, +scale, +scale));
	temp -> Insert_Corn(Point3D(+scale, +scale, +scale));

	temp -> Insert_Face4(FaceCorner(0b000), FaceCorner(0b010), FaceCorner(0b001), FaceCorner(0b011));
	temp -> Insert_Face4(FaceCorner(0b000), FaceCorner(0b100), FaceCorner(0b010), FaceCorner(0b110));
	temp -> Insert_Face4(FaceCorner(0b000), FaceCorner(0b001), FaceCorner(0b100), FaceCorner(0b101));

	temp -> Insert_Face4(FaceCorner(0b111), FaceCorner(0b110), FaceCorner(0b101), FaceCorner(0b100));
	temp -> Insert_Face4(FaceCorner(0b111), FaceCorner(0b101), FaceCorner(0b011), FaceCorner(0b001));
	temp -> Insert_Face4(FaceCorner(0b111), FaceCorner(0b011), FaceCorner(0b110), FaceCorner(0b010));

	temp -> Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.00f, 0.00f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)), Skin2DFaceCorner(Point2D(0.25f, 0.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.25f, 0.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)), Skin2DFaceCorner(Point2D(0.50f, 0.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.50f, 0.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)), Skin2DFaceCorner(Point2D(0.75f, 0.00f)), Skin2DFaceCorner(Point2D(0.75f, 0.50f)));

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.25f, 1.00f)), Skin2DFaceCorner(Point2D(0.00f, 1.00f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)), Skin2DFaceCorner(Point2D(0.00f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.50f, 1.00f)), Skin2DFaceCorner(Point2D(0.25f, 1.00f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)), Skin2DFaceCorner(Point2D(0.25f, 0.50f)));
	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.75f, 1.00f)), Skin2DFaceCorner(Point2D(0.50f, 1.00f)), Skin2DFaceCorner(Point2D(0.75f, 0.50f)), Skin2DFaceCorner(Point2D(0.50f, 0.50f)));

	skin -> Done();


	temp -> Skin = skin;
	return temp;
}
YMT::PolyHedra * YMT::PolyHedra::ConeC(int segments, float width, float height)
{
	PolyHedra * temp = new PolyHedra();

	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	Angle3D angle;

	int idx_frst = temp -> Corners.Count();
	temp -> Insert_Corn(Point3D(0, 0, +height));
	for (int i = 0; i < segments; i++)
	{
		angle.Z = (TAU * i) / segments;
		angle.CalcFore();
		temp -> Insert_Corn(angle.rotate(Point3D(0, +width, -height)));
	}
	int idx_last = temp -> Corners.Count();
	temp -> Insert_Corn(Point3D(0, 0, -height));

	for (int i = 0; i < segments; i++)
	{
		float tex0 = (0.0f + i) / segments;
		float tex1 = (1.0f + i) / segments;
		float texM = (0.5f + i) / segments;

		int idx_curr = ((i + 0) % segments) + 1;
		int idx_next = ((i + 1) % segments) + 1;

		temp -> Insert_Face4(
			FaceCorner(idx_frst),
			FaceCorner(idx_next),
			FaceCorner(idx_curr),
			FaceCorner(idx_last)
		);

		skin -> Insert_Face4(
			Skin2DFaceCorner(Point2D(texM, 0.0f)),
			Skin2DFaceCorner(Point2D(tex1, 1.0f)),
			Skin2DFaceCorner(Point2D(tex0, 1.0f)),
			Skin2DFaceCorner(Point2D(texM, 0.0f))
		);
	}

	temp -> Done();
	return temp;
}
YMT::PolyHedra * YMT::PolyHedra::FullTexture(Image * img, float scale)
{
	PolyHedra * temp = new PolyHedra();

	temp -> Insert_Corn(Point3D(-scale, -scale, 0));
	temp -> Insert_Corn(Point3D(-scale, +scale, 0));
	temp -> Insert_Corn(Point3D(+scale, -scale, 0));
	temp -> Insert_Corn(Point3D(+scale, +scale, 0));

	temp -> Insert_Face4(FaceCorner(0), FaceCorner(1), FaceCorner(2), FaceCorner(3));

	temp -> Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = img -> W;
	skin -> H = img -> H;
	skin -> Images.Insert(img);

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.0f, 1.0f)), Skin2DFaceCorner(Point2D(0.0f, 0.0f)), Skin2DFaceCorner(Point2D(1.0f, 1.0f)), Skin2DFaceCorner(Point2D(1.0f, 0.0f)));

	skin -> Done();


	temp -> Skin = skin;
	return temp;
}





PolyHedra_MainData * YMT::PolyHedra::ToMainData(int & count)
{
	count = Faces.Count() * 3;
	PolyHedra_MainData * data = new PolyHedra_MainData[count];

	for (unsigned int f = 0; f < Faces.Count(); f++)
	{
		int c = f * 3;
		const Face & face = Faces[f];
		if (face.Corner0.Udx < Corners.Count() &&
			face.Corner1.Udx < Corners.Count() &&
			face.Corner2.Udx < Corners.Count())
		{
			const Corner & cornerX = Corners[face.Corner0.Udx];
			const Corner & cornerY = Corners[face.Corner1.Udx];
			const Corner & cornerZ = Corners[face.Corner2.Udx];

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
		}
		else
		{
			//std::cout << "Invalid Face\n";
		}
	}

	if (Skin == NULL)
	{
		for (int i = 0; i < count; i++)
		{
			data[i].Texture = Point2D();
		}
	}
	else
	{
		const Skin2DA * skin = (const Skin2DA *)Skin;
		for (unsigned int f = 0; f < skin -> Faces.Count(); f++)
		{
			int c = f * 3;
			const Skin2DFace & face = ((Skin2DA*)Skin) -> Faces[f];
			data[c + 0].Texture = face.Corner0.Tex;
			data[c + 1].Texture = face.Corner1.Tex;
			data[c + 2].Texture = face.Corner2.Tex;
		}
	}

	/*for (int i = 0; i < count; i++)
	{
		std::cout << "Main: " << data[i].Position << " : " << data[i].Normal << " : " << data[i].Texture << "\n";
	}*/

	return data;
}

std::string YMT::PolyHedra::ToInfo() const
{
	std::ostringstream ss;

	ss << "PolyHedra Info";
	ss << "\n" << "Corner Count: " << Corners.Count();
	ss << "\n" << "Face Count: " << Faces.Count();

	return ss.str();
}

AxisBox3D	YMT::PolyHedra::CalcBound() const
{
	AxisBox3D box;
	for (unsigned int i = 0; i < Corners.Count(); i++)
	{
		box.Consider(Corners[i].Position);
	}
	return box;
}
