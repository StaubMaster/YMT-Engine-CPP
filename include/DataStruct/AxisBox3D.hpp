
#ifndef  AXISBOX_3D_HPP
# define AXISBOX_3D_HPP

#include "Point3D.hpp"

struct AxisBox3D
{
	public:
		Point3D	Min;
		Point3D	Max;

	public:
		AxisBox3D();

	public:
		void Consider(Point3D p);

	public:
		Point3D Size() const;
		Point3D Center() const;
};

#endif
