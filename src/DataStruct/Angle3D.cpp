#include "DataStruct/Angle3D.hpp"
#include "DataStruct/Point3D.hpp"

#include <math.h>
#include <iostream>



Angle3D::Angle3D() : X(0), Y(0), Z(0)
{
	MatrixDefault(Data);
}
Angle3D::Angle3D(float x, float y, float z) : X(x), Y(y), Z(z)
{
	MatrixDefault(Data);
}
Angle3D::~Angle3D()
{

}



Angle3D::Angle3D(const Angle3D & other) : X(other.X), Y(other.Y), Z(other.Z)
{
	MatrixCopy(Data, other.Data);
}
const Angle3D & Angle3D::operator =(const Angle3D & other)
{
	this -> X = other.X;
	this -> Y = other.Y;
	this -> Z = other.Z;

	MatrixCopy(this -> Data, other.Data);

	return *this;
}



Angle3D Angle3D::FromPoint3D(const Point3D & dir)
{
	float len = dir.length();

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



void Angle3D::MatrixToString(float data[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			if (j != 0) { std::cout << " | "; }
			std::cout << data[i][j];
		}
		std::cout << " ]";
		std::cout << "\n";
	}
}
void Angle3D::MatrixDefault(float data[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				data[i][j] = 1;
			}
			else
			{
				data[i][j] = 0;
			}
		}
	}
}
void Angle3D::MatrixCopy(float result[3][3], const float mat[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = mat[i][j];
		}
	}
}
void Angle3D::MatrixTransPose(float result[3][3], const float mat[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			result[i][j] = mat[j][i];
		}
	}
}
void Angle3D::MatrixMultiply(float result[3][3], const float mat0[3][3], const float mat1[3][3])
{
/*
	C00 = (A00 * B00) + (A01 * B10) + (A02 * B20)
	C01 = (A00 * B01) + (A01 * B11) + (A02 * B21)
	C02 = (A00 * B02) + (A01 * B12) + (A02 * B22)

	C10 = (A10 * B00) + (A11 * B10) + (A12 * B20)
	C11 = (A10 * B01) + (A11 * B11) + (A12 * B21)
	C12 = (A10 * B02) + (A11 * B12) + (A12 * B22)
	
	C20 = (A20 * B00) + (A21 * B10) + (A22 * B20)
	C21 = (A20 * B01) + (A21 * B11) + (A22 * B21)
	C22 = (A20 * B02) + (A21 * B12) + (A22 * B22)
	
	Cij = (Ain * Bnj) + (Ain * Bnj) + (Ain * Bnj)
*/
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float sum = 0;
			for (int n = 0; n < 3; n++)
			{
				sum += mat0[i][n] * mat1[n][j];
			}
			result[i][j] = sum;
		}
	}
}



void Angle3D::CalcFore()
{
	float sinX = sin(X);
	float cosX = cos(X);
	float matX[3][3] = {
		{ +cosX , 0 , -sinX },
		{   0   , 1 ,   0   },
		{ +sinX , 0 , +cosX },
	};

	float sinY = sin(Y);
	float cosY = cos(Y);
	float matY[3][3] = {
		{ 1 ,   0   ,   0   },
		{ 0 , +cosY , -sinY },
		{ 0 , +sinY , +cosY },
	};

	float sinZ = sin(Z);
	float cosZ = cos(Z);
	float matZ[3][3] = {
		{ +cosZ , +sinZ , 0 },
		{ -sinZ , +cosZ , 0 },
		{   0   ,   0   , 1 },
	};

	float temp[3][3];
	MatrixDefault(temp);
	MatrixMultiply(Data, temp, matZ);
	MatrixMultiply(temp, Data, matY);
	MatrixMultiply(Data, temp, matX);
}
void Angle3D::CalcBack()
{
	float sinZ = sin(Z);
	float cosZ = cos(Z);
	float matZ[3][3] = {
		{ +cosZ , -sinZ , 0 },
		{ +sinZ , +cosZ , 0 },
		{   0   ,   0   , 1 },
	};

	float sinY = sin(Y);
	float cosY = cos(Y);
	float matY[3][3] = {
		{ 1 ,   0   ,   0   },
		{ 0 , +cosY , +sinY },
		{ 0 , -sinY , +cosY },
	};

	float sinX = sin(X);
	float cosX = cos(X);
	float matX[3][3] = {
		{ +cosX , 0 , +sinX },
		{   0   , 1 ,   0   },
		{ -sinX , 0 , +cosX },
	};

	float temp[3][3];
	MatrixDefault(temp);
	MatrixMultiply(Data, temp, matX);
	MatrixMultiply(temp, Data, matY);
	MatrixMultiply(Data, temp, matZ);
}



Point3D	Angle3D::rotate(Point3D p) const
{
	Point3D n;
	n.X = (Data[0][0] * p.X) + (Data[0][1] * p.Y) + (Data[0][2] * p.Z);
	n.Y = (Data[1][0] * p.X) + (Data[1][1] * p.Y) + (Data[1][2] * p.Z);
	n.Z = (Data[2][0] * p.X) + (Data[2][1] * p.Y) + (Data[2][2] * p.Z);
	return (n);
}
/*Point3D	Angle3D::rotate_fore(Point3D p) const
{
	rotate(p.X, p.Z, cos(X), sin(X));
	rotate(p.Y, p.Z, cos(Y), sin(Y));
	rotate(p.Y, p.X, cos(Z), sin(Z));
	return (p);
}*/
/*Point3D	Angle3D::rotate_back(Point3D p) const
{
	rotate(p.X, p.Y, cos(Z), sin(Z));
	rotate(p.Z, p.Y, cos(Y), sin(Y));
	rotate(p.Z, p.X, cos(X), sin(X));
	return (p);
}*/

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
/*Angle3D	Angle3D::rotate_fore(Angle3D a) const
{
	Point3D pX, pY, pZ;
	pX = a.rotate_fore(rotate_fore(Point3D(1, 0, 0)));
	pY = a.rotate_fore(rotate_fore(Point3D(0, 1, 0)));
	pZ = a.rotate_fore(rotate_fore(Point3D(0, 0, 1)));

	return Angle3D(
		atan2f(pX.Z, pZ.Z),
		asinf(pY.Z),
		atan2(pY.X, pY.Y)
	);
}*/
/*Angle3D	Angle3D::rotate_back(Angle3D a) const
{
	Point3D pX, pY, pZ;
	pX = a.rotate_back(rotate_back(Point3D(1, 0, 0)));
	pY = a.rotate_back(rotate_back(Point3D(0, 1, 0)));
	pZ = a.rotate_back(rotate_back(Point3D(0, 0, 1)));

	return Angle3D(
		atan2f(pZ.X, pZ.Z),
		asinf(pZ.Y),
		atan2(pX.Y, pY.Y)
	);
}*/


void	Angle3D::rotate(float & pls, float & mns, float cos, float sin)
{
	float	tmp;
	tmp = pls * cos - mns * sin;
	mns = mns * cos + pls * sin;
	pls = tmp;
}





/*std::ostream & operator <<(std::ostream & o, const Angle3D & a)
{
	o << "( " << a.x << " | " << a.y << " | " << a.z << " )";
	o << "#( " << a.sin_x << " | " << a.sin_y << " | " << a.sin_z << " )";
	o << "#( " << a.cos_x << " | " << a.cos_y << " | " << a.cos_z << " )";
	return o;
}*/
