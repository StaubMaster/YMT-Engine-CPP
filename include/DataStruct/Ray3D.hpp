
#ifndef  RAY_3D_HPP
# define RAY_3D_HPP

# include "Point3D.hpp"

struct Ray3D
{
	public:
		Point3D Pos;
		Point3D Dir;

	public:
		Ray3D();
		Ray3D(Point3D pos, Point3D dir);



	public:
		class Interval
		{
			public:
				const Ray3D & Ray;
				const float Inter;
				const int Index;
			public:
				Interval(const Ray3D & ray, float inter, int index);
			public:
				Point3D	ToPoint() const;
		};

	public:
		Interval Ray_Point(Point3D p);
};

#endif
