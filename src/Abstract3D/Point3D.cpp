#include "../../include/Abstract3D/Point3D.hpp"

Point3D::Point3D()
{
	X = 0;
	Y = 0;
	Z = 0;
}
Point3D::Point3D(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}
Point3D::~Point3D()
{

}



Point3D::Point3D(const Point3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
}
const Point3D & Point3D::operator =(const Point3D & other)
{
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	return *this;
}



float Point3D::length2() const
{
	return ((X * X) + (Y * Y) + (Z * Z));
}
float Point3D::length() const
{
	return sqrt(length2());
}
Point3D Point3D::normalize() const
{
	float len = length();
	return Point3D(
		X / len,
		Y / len,
		Z / len
	);
}




Point3D Point3D::operator +() const
{
	return Point3D(
		+X,
		+Y,
		+Z
	);
}
Point3D Point3D::operator -() const
{
	return Point3D(
		-X,
		-Y,
		-Z
	);
}
Point3D Point3D::operator !() const
{
	return normalize();
}



Point3D Point3D::operator +(const Point3D & other) const
{
	return Point3D(
		X + other.X,
		Y + other.Y,
		Z + other.Z
	);
}
Point3D Point3D::operator -(const Point3D & other) const
{
	return Point3D(
		X - other.X,
		Y - other.Y,
		Z - other.Z
	);
}
Point3D Point3D::operator *(const Point3D & other) const
{
	return Point3D(
		X * other.X,
		Y * other.Y,
		Z * other.Z
	);
}
Point3D Point3D::operator /(const Point3D & other) const
{
	return Point3D(
		X / other.X,
		Y / other.Y,
		Z / other.Z
	);
}



Point3D Point3D::operator +(const float & flt) const
{
	return Point3D(
		X + flt,
		Y + flt,
		Z + flt
	);
}
Point3D Point3D::operator -(const float & flt) const
{
	return Point3D(
		X - flt,
		Y - flt,
		Z - flt
	);
}
Point3D Point3D::operator *(const float & flt) const
{
	return Point3D(
		X * flt,
		Y * flt,
		Z * flt
	);
}
Point3D Point3D::operator /(const float & flt) const
{
	return Point3D(
		X / flt,
		Y / flt,
		Z / flt
	);
}



float Point3D::dot(const Point3D & p0, const Point3D & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y) +
		(p0.Z * p1.Z)
	);
}
float Point3D::operator %(const Point3D & other) const
{
	return dot(*this, other);
}



Point3D Point3D::cross(const Point3D & p0, const Point3D & p1)
{
	return Point3D(
		p0.Y * p1.Z - p0.Z * p1.Y,
		p0.Z * p1.X - p0.X * p1.Z,
		p0.X * p1.Y - p0.Y * p1.X
	);
}
Point3D Point3D::operator ^(const Point3D & other) const
{
	return cross(*this, other);
}



/*std::ostream & operator <<(std::ostream & o, const Point3D & idx)
{

}*/
