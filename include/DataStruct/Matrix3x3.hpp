#ifndef  MATRIX_3_3_HPP
# define MATRIX_3_3_HPP

struct Point3D;

class Matrix3x3
{
	public:
		float Data[3][3];

	public:
		Matrix3x3();
		Matrix3x3(const Matrix3x3 & other);
		Matrix3x3 & operator =(const Matrix3x3 & other);
		Matrix3x3(const float * data);

		static Matrix3x3 Default();

	public:
		Matrix3x3 operator*(const Matrix3x3 & other) const;

	public:
		Point3D Multiply0(const Point3D & p) const;
		Point3D Multiply1(const Point3D & p) const;

	public:
		Matrix3x3 TransPose() const;
		void ToString() const;
};

#endif