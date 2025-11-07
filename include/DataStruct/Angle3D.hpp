
#ifndef ANGLE_3D_HPP
# define ANGLE_3D_HPP

# define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
# define TAU 6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413

# include "Matrix3x3.hpp"

struct Point3D;

struct Angle3D
{
	public:
		float	X;
		float	Y;
		float	Z;

	public:
		Matrix3x3	Mat;

	public:
		Angle3D();
		Angle3D(float x, float y, float z);
		~Angle3D();

		Angle3D(const Angle3D & other);
		const Angle3D & operator =(const Angle3D & other);

		static Angle3D FromPoint3D(const Point3D & dir);

		static float DegreeToRadian(float degree);
		static float RadianToDegree(float radian);

	private:
	public:
		void	CalcFore();
		void	CalcBack();

		Point3D	rotate(Point3D p) const;
		Angle3D	rotate(Angle3D a) const;
};

#endif
