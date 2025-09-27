#include "Abstract3D/Transformation3D.hpp"



Transformation3D::Transformation3D()
{
	Pos = Point3D();
	Rot = Angle3D();
}
Transformation3D::Transformation3D(Point3D pos, Angle3D rot)
{
	Pos = pos;
	Rot = rot;
}
Transformation3D::~Transformation3D()
{

}



void Transformation3D::MoveFlatX(Point3D move)
{
	Pos = Pos + (Angle3D(Rot.x, 0, 0).rotate_back(move));
}
void Transformation3D::SpinFlatX(Angle3D spin)
{
	Rot.x = Rot.x + spin.x;
	Rot.y = Rot.y + spin.y;
	Rot.z = 0;
	Rot.UpdateSinCos();
}
void Transformation3D::TransformFlatX(Point3D move, Angle3D spin)
{
	MoveFlatX(move);
	SpinFlatX(spin);
}
