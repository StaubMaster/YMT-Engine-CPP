#include "DataStruct/Trans3D.hpp"



Trans3D::Trans3D()
{
	Pos = Point3D();
	Rot = Angle3D();
}
Trans3D::Trans3D(Point3D pos, Angle3D rot)
{
	Pos = pos;
	Rot = rot;
}
Trans3D::~Trans3D()
{

}



void Trans3D::MoveFlatX(Point3D move)
{
	Angle3D a(Rot.X, 0, 0);
	a.CalcBack();
	Pos = Pos + a.rotate(move);
	//Pos = Pos + (Angle3D(Rot.X, 0, 0).rotate(move));
}
void Trans3D::SpinFlatX(Angle3D spin)
{
	Rot.X = Rot.X + spin.X;
	Rot.Y = Rot.Y + spin.Y;
	Rot.Z = 0;
}
void Trans3D::TransformFlatX(Point3D move, Angle3D spin)
{
	MoveFlatX(move);
	SpinFlatX(spin);
}
