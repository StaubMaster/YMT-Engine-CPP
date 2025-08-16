#ifndef POINT_2D_HPP
# define POINT_2D_HPP

#include <math.h>

class Point2D
{
	public:
		float	X;
		float	Y;

	public:
		Point2D();
		Point2D(float x, float y);
		~Point2D();

		Point2D(const Point2D & other);
		const Point2D & operator =(const Point2D & other);

	public:
		float length2() const;
		float length() const;
		Point2D normalize() const;

		Point2D operator +() const;
		Point2D operator -() const;
		Point2D operator !() const;

		Point2D operator +(const Point2D & other) const;
		Point2D operator -(const Point2D & other) const;
		Point2D operator *(const Point2D & other) const;
		Point2D operator /(const Point2D & other) const;

		Point2D operator +(const float & flt) const;
		Point2D operator -(const float & flt) const;
		Point2D operator *(const float & flt) const;
		Point2D operator /(const float & flt) const;

		float static dot(const Point2D & p0, const Point2D & p1);
		float operator %(const Point2D & other) const;
};

#endif