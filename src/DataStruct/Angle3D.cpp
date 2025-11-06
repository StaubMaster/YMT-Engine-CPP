#include "DataStruct/Angle3D.hpp"
#include "DataStruct/Point3D.hpp"

#include <math.h>
#include <iostream>



Angle3D::Angle3D() : X(0), Y(0), Z(0),
	Mat(Matrix3x3::Default())
{ }
Angle3D::Angle3D(float x, float y, float z) : X(x), Y(y), Z(z),
	Mat(Matrix3x3::Default())
{ }
Angle3D::~Angle3D()
{ }



Angle3D::Angle3D(const Angle3D & other) : X(other.X), Y(other.Y), Z(other.Z),
	Mat(other.Mat)
{ }
const Angle3D & Angle3D::operator =(const Angle3D & other)
{
	this -> X = other.X;
	this -> Y = other.Y;
	this -> Z = other.Z;
	this -> Mat = other.Mat;
	return *this;
}



Angle3D Angle3D::FromPoint3D(const Point3D & dir)
{
	float len = sqrt((dir.X * dir.X) + (dir.Z * dir.Z));

	Angle3D a(
		atan2(dir.X, dir.Z),
		atan2(dir.Y, len),
		0
	);

	return a;
}



float Angle3D::DegreeToRadian(float degree)
{
	return ((degree * TAU) / 360);
}
float Angle3D::RadianToDegree(float radian)
{
	return ((radian * 360) / TAU);
}



void Angle3D::CalcFore()
{
	float sinX = sin(X);
	float cosX = cos(X);
	Matrix3x3 matX((float[]) {
		 +cosX , 0 , -sinX ,
		   0   , 1 ,   0   ,
		 +sinX , 0 , +cosX ,
	});

	float sinY = sin(Y);
	float cosY = cos(Y);
	Matrix3x3 matY((float[]) {
		 1 ,   0   ,   0   ,
		 0 , +cosY , -sinY ,
		 0 , +sinY , +cosY ,
	});

	float sinZ = sin(Z);
	float cosZ = cos(Z);
	Matrix3x3 matZ((float[]) {
		 +cosZ , +sinZ , 0 ,
		 -sinZ , +cosZ , 0 ,
		   0   ,   0   , 1 ,
	});

	Mat = Matrix3x3::Default();
	Mat = Mat * matZ;
	Mat = Mat * matY;
	Mat = Mat * matX;
}
void Angle3D::CalcBack()
{
	float sinZ = sin(Z);
	float cosZ = cos(Z);
	Matrix3x3 matZ((float[]) {
		 +cosZ , -sinZ , 0 ,
		 +sinZ , +cosZ , 0 ,
		   0   ,   0   , 1 ,
	});

	float sinY = sin(Y);
	float cosY = cos(Y);
	Matrix3x3 matY((float[]) {
		 1 ,   0   ,   0   ,
		 0 , +cosY , +sinY ,
		 0 , -sinY , +cosY ,
	});

	float sinX = sin(X);
	float cosX = cos(X);
	Matrix3x3 matX((float[]) {
		 +cosX , 0 , +sinX ,
		   0   , 1 ,   0   ,
		 -sinX , 0 , +cosX ,
	});

	Mat = Matrix3x3::Default();
	Mat = Mat * matX;
	Mat = Mat * matY;
	Mat = Mat * matZ;
}



Point3D	Angle3D::rotate(Point3D p) const
{
	return Mat.Multiply0(p);
}

Angle3D	Angle3D::rotate(Angle3D a) const
{
	Point3D pX, pY, pZ;
	pX = a.rotate(rotate(Point3D(1, 0, 0)));
	pY = a.rotate(rotate(Point3D(0, 1, 0)));
	pZ = a.rotate(rotate(Point3D(0, 0, 1)));

	return Angle3D(
		atan2f(pX.Z, pZ.Z),
		asinf(pY.Z),
		atan2(pY.X, pY.Y)
	);
}
