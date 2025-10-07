
#ifndef ANGLE_3D_HPP
# define ANGLE_3D_HPP

struct Point3D;

struct Angle3D
{
	public:
		float	X;
		float	Y;
		float	Z;

	//private:
		float	Data[3][3];

	public:
		Angle3D();
		Angle3D(float x, float y, float z);
		~Angle3D();

		Angle3D(const Angle3D & other);
		const Angle3D & operator =(const Angle3D & other);

	public:
		static void	MatrixToString(float mat[3][3]);
		static void	MatrixDefault(float mat[3][3]);
		static void	MatrixMultiply(float result[3][3], float mat0[3][3], float mat1[3][3]);
	private:
	public:
		void	CalcFore();
		void	CalcBack();

		Point3D	rotate(Point3D p) const;
		//Point3D	rotate_fore(Point3D p) const;
		//Point3D	rotate_back(Point3D p) const;

		Angle3D	rotate(Angle3D a) const;
		//Angle3D	rotate_fore(Angle3D a) const;
		//Angle3D	rotate_back(Angle3D a) const;

	public:
		static void	rotate(float & pls, float & mns, float cos, float sin);
};

#endif
