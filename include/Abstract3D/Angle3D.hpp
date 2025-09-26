
#ifndef ANGLE_3D_HPP
# define ANGLE_3D_HPP
# include <math.h>
# include "Point3D.hpp"

class Angle3D
{
	public:
		float	sin_x;
		float	sin_y;
		float	sin_z;
		float	cos_x;
		float	cos_y;
		float	cos_z;
		float	x;
		float	y;
		float	z;

	public:
		Angle3D();
		Angle3D(float x, float y, float z);
		~Angle3D();

		Angle3D(const Angle3D & other);
		const Angle3D & operator =(const Angle3D & other);

	public:
		void UpdateSinCos();

		Point3D	rotate_fore(Point3D p) const;
		Point3D	rotate_back(Point3D p) const;

		Angle3D	rotate_fore(Angle3D a) const;
		Angle3D	rotate_back(Angle3D a) const;

	public:
		static void	rotate(float & pls, float & mns, float cos, float sin);
};

std::ostream & operator <<(std::ostream & o, const Angle3D & idx);

#endif
