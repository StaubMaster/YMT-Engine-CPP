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
	Pos = Pos + (Angle3D(Rot.x, 0, 0).rotate_back(move));
}
void Trans3D::SpinFlatX(Angle3D spin)
{
	Rot.x = Rot.x + spin.x;
	Rot.y = Rot.y + spin.y;
	Rot.z = 0;
	Rot.UpdateSinCos();
}
void Trans3D::TransformFlatX(Point3D move, Angle3D spin)
{
	MoveFlatX(move);
	SpinFlatX(spin);
}
