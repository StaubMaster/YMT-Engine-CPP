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
