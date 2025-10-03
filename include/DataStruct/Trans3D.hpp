#ifndef TRANS_3D_HPP
# define TRANS_3D_HPP

# include "Point3D.hpp"
# include "Angle3D.hpp"

struct Trans3D
{
	public:
		Point3D	Pos;
		Angle3D	Rot;

	public:
		Trans3D();
		Trans3D(Point3D pos, Angle3D rot);
		~Trans3D();

	public:
		void MoveFlatX(Point3D move);
		void SpinFlatX(Angle3D spin);
		void TransformFlatX(Point3D move, Angle3D spin);
};

#endif
