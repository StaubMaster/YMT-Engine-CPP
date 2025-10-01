#include "DataStruct/Point2D.hpp"

#include <math.h>



Point2D::Point2D()
{
	X = 0;
	Y = 0;
}
Point2D::Point2D(float x, float y)
{
	X = x;
	Y = y;
}
Point2D::~Point2D()
{

}



Point2D::Point2D(const Point2D & other)
{
	X = other.X;
	Y = other.Y;
}
const Point2D & Point2D::operator =(const Point2D & other)
{
	X = other.X;
	Y = other.Y;
	return *this;
}



float Point2D::length2() const
{
	return ((X * X) + (Y * Y));
}
float Point2D::length() const
{
	return sqrt(length2());
}
Point2D Point2D::normalize() const
{
	float len = length();
	return Point2D(
		X / len,
		Y / len
	);
}




Point2D Point2D::operator +() const
{
	return Point2D(
		+X,
		+Y
	);
}
Point2D Point2D::operator -() const
{
	return Point2D(
		-X,
		-Y
	);
}
Point2D Point2D::operator !() const
{
	return normalize();
}



Point2D Point2D::operator +(const Point2D & other) const
{
	return Point2D(
		X + other.X,
		Y + other.Y
	);
}
Point2D Point2D::operator -(const Point2D & other) const
{
	return Point2D(
		X - other.X,
		Y - other.Y
	);
}
Point2D Point2D::operator *(const Point2D & other) const
{
	return Point2D(
		X * other.X,
		Y * other.Y
	);
}
Point2D Point2D::operator /(const Point2D & other) const
{
	return Point2D(
		X / other.X,
		Y / other.Y
	);
}



Point2D Point2D::operator +(const float & flt) const
{
	return Point2D(
		X + flt,
		Y + flt
	);
}
Point2D Point2D::operator -(const float & flt) const
{
	return Point2D(
		X - flt,
		Y - flt
	);
}
Point2D Point2D::operator *(const float & flt) const
{
	return Point2D(
		X * flt,
		Y * flt
	);
}
Point2D Point2D::operator /(const float & flt) const
{
	return Point2D(
		X / flt,
		Y / flt
	);
}



float Point2D::dot(const Point2D & p0, const Point2D & p1)
{
	return (
		(p0.X * p1.X) +
		(p0.Y * p1.Y)
	);
}
float Point2D::operator %(const Point2D & other) const
{
	return dot(*this, other);
}



/*std::ostream & operator <<(std::ostream & o, const Point2D & idx)
{

}*/
