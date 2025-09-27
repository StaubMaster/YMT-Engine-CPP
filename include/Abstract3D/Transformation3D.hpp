#ifndef TRANS_3D_HPP
# define TRANS_3D_HPP

# include "Point3D.hpp"
# include "Angle3D.hpp"

class Transformation3D
{
	public:
		Point3D	Pos;
		Angle3D	Rot;

	public:
		Transformation3D();
		Transformation3D(Point3D pos, Angle3D rot);
		~Transformation3D();

	public:
		void MoveFlatX(Point3D move);
		void SpinFlatX(Angle3D spin);
		void TransformFlatX(Point3D move, Angle3D spin);
};

#endif