#include "DataStruct/AxisBox3D.hpp"
#include <math.h>



AxisBox3D::AxisBox3D() :
	Min(+INFINITY, +INFINITY, +INFINITY),
	Max(-INFINITY, -INFINITY, -INFINITY)
{

}



void AxisBox3D::Consider(Point3D p)
{
	if (p.X < Min.X) { Min.X = p.X; }
	if (p.Y < Min.Y) { Min.Y = p.Y; }
	if (p.Z < Min.Z) { Min.Z = p.Z; }

	if (p.X > Max.X) { Max.X = p.X; }
	if (p.Y > Max.Y) { Max.Y = p.Y; }
	if (p.Z > Max.Z) { Max.Z = p.Z; }
}


Point3D AxisBox3D::Size() const
{
	return (Max - Min);
}
Point3D AxisBox3D::Center() const
{
	return ((Max * 0.5f) + (Min * 0.5f));
}
