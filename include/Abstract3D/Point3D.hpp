
#ifndef POINT_3D_HPP
# define POINT_3D_HPP
# include <math.h>
# include <iostream>

class Point3D
{
	public:
		float	X;
		float	Y;
		float	Z;

	public:
		Point3D();
		Point3D(float x, float y, float z);
		~Point3D();

		Point3D(const Point3D & other);
		const Point3D & operator =(const Point3D & other);

	public:
		float length2() const;
		float length() const;
		Point3D normalize() const;

		Point3D operator +() const;
		Point3D operator -() const;
		Point3D operator !() const;

		Point3D operator +(const Point3D & other) const;
		Point3D operator -(const Point3D & other) const;
		Point3D operator *(const Point3D & other) const;
		Point3D operator /(const Point3D & other) const;

		Point3D operator +(const float & flt) const;
		Point3D operator -(const float & flt) const;
		Point3D operator *(const float & flt) const;
		Point3D operator /(const float & flt) const;

		float static dot(const Point3D & p0, const Point3D & p1);
		float operator %(const Point3D & other) const;

		Point3D static cross(const Point3D & p0, const Point3D & p1);
		Point3D operator ^(const Point3D & other) const;
};

std::ostream & operator <<(std::ostream & o, const Point3D & idx);

#endif