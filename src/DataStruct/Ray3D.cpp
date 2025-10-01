#include "DataStruct/Ray3D.hpp"
#include "DataStruct/Point3D.hpp"

#include <math.h>



Ray3D::Ray3D(Point3D pos, Point3D dir) :
	Pos(pos), Dir(dir) { }



Ray3D::Interval::Interval(const Ray3D & ray, float inter = NAN, int index = -1) :
	Ray(ray), Inter(inter), Index(index) { }



Ray3D::Interval Ray3D::Ray_Point(Point3D p)
{
	float dot = Point3D::dot(Dir, Pos - p);
	float sqr = Dir.length2();
	return Ray3D::Interval(*this, -(dot / sqr));
}
