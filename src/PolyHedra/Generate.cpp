#include "PolyHedra/Generate.hpp"
#include "PolyHedra/Data.hpp"
#include "PolyHedra/Template.hpp"

#include "PolyHedra/Skin/SkinBase.hpp"
#include "PolyHedra/Skin/Skin2DA.hpp"
#include "Graphics/Texture/Generate.hpp"

#include "DataStruct/Angle3D.hpp"

#include "Format/Image.hpp"



YMT::PolyHedra * YMT::PolyHedra::Generate::Cube(float scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	temp.Insert_Corn(Point3D(-scale, -scale, -scale));
	temp.Insert_Corn(Point3D(+scale, -scale, -scale));
	temp.Insert_Corn(Point3D(-scale, +scale, -scale));
	temp.Insert_Corn(Point3D(+scale, +scale, -scale));
	temp.Insert_Corn(Point3D(-scale, -scale, +scale));
	temp.Insert_Corn(Point3D(+scale, -scale, +scale));
	temp.Insert_Corn(Point3D(-scale, +scale, +scale));
	temp.Insert_Corn(Point3D(+scale, +scale, +scale));

	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b010), FaceCorner(0b001), FaceCorner(0b011));
	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b100), FaceCorner(0b010), FaceCorner(0b110));
	temp.Insert_Face4(FaceCorner(0b000), FaceCorner(0b001), FaceCorner(0b100), FaceCorner(0b101));

	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b110), FaceCorner(0b101), FaceCorner(0b100));
	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b101), FaceCorner(0b011), FaceCorner(0b001));
	temp.Insert_Face4(FaceCorner(0b111), FaceCorner(0b011), FaceCorner(0b110), FaceCorner(0b010));

	temp.Done();


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


	ph -> Skin = skin;
	return ph;
}



YMT::PolyHedra * YMT::PolyHedra::Generate::ConeC(int segments, float width, float height)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	Skin2DA * skin = new Skin2DA();
	skin -> W = 8;
	skin -> H = 4;
	skin -> Images.Insert(Texture::Generate::Orientation3D());

	Angle3D angle;

	int idx_frst = ph -> Corners.Count();
	temp.Insert_Corn(Point3D(0, 0, +height));
	for (int i = 0; i < segments; i++)
	{
		angle.Z = (TAU * i) / segments;
		angle.CalcFore();
		temp.Insert_Corn(angle.rotate(Point3D(0, +width, -height)));
	}
	int idx_last = ph -> Corners.Count();
	temp.Insert_Corn(Point3D(0, 0, -height));

	for (int i = 0; i < segments; i++)
	{
		float tex0 = (0.0f + i) / segments;
		float tex1 = (1.0f + i) / segments;
		float texM = (0.5f + i) / segments;

		int idx_curr = ((i + 0) % segments) + 1;
		int idx_next = ((i + 1) % segments) + 1;

		temp.Insert_Face4(
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

	temp.Done();
	return ph;
}



YMT::PolyHedra * YMT::PolyHedra::Generate::FullTexture(Image * img, float scale)
{
	PolyHedra * ph = new PolyHedra();
	PolyHedra::Template temp(*ph);

	temp.Insert_Corn(Point3D(-scale, -scale, 0));
	temp.Insert_Corn(Point3D(-scale, +scale, 0));
	temp.Insert_Corn(Point3D(+scale, -scale, 0));
	temp.Insert_Corn(Point3D(+scale, +scale, 0));

	temp.Insert_Face4(FaceCorner(0), FaceCorner(1), FaceCorner(2), FaceCorner(3));

	temp.Done();


	Skin2DA * skin = new Skin2DA();
	skin -> W = img -> W;
	skin -> H = img -> H;
	skin -> Images.Insert(img);

	skin -> Insert_Face4(Skin2DFaceCorner(Point2D(0.0f, 1.0f)), Skin2DFaceCorner(Point2D(0.0f, 0.0f)), Skin2DFaceCorner(Point2D(1.0f, 1.0f)), Skin2DFaceCorner(Point2D(1.0f, 0.0f)));

	skin -> Done();


	ph -> Skin = skin;
	return ph;
}

