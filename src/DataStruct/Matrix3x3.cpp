#include "DataStruct/Matrix3x3.hpp"
#include "DataStruct/Point3D.hpp"



Matrix3x3::Matrix3x3()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = 0;
		}
	}
}
Matrix3x3::Matrix3x3(const Matrix3x3 & other)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
}
Matrix3x3 & Matrix3x3::operator =(const Matrix3x3 & other)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			Data[x][y] = other.Data[x][y];
		}
	}
	return *this;
}

Matrix3x3::Matrix3x3(const float * data)
{
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			Data[x][y] = data[y + x * 3];
		}
	}
}



Matrix3x3 Matrix3x3::Default()
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mat.Data[x][y] = (x == y);
		}
	}
	return mat;
}



Matrix3x3 Matrix3x3::operator *(const Matrix3x3 & other) const
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			float sum = 0;
			for (int n = 0; n < 3; n++)
			{
				sum += Data[x][n] * other.Data[n][y];
			}
			mat.Data[x][y] = sum;
		}
	}
	return mat;
}



Point3D Matrix3x3::Multiply0(const Point3D & p) const
{
	float flt[3] = { p.X, p.Y, p.Z };
	float n[3];
	for (int x = 0; x < 3; x++)
	{
		float sum = 0;
		for (int y = 0; y < 3; y++)
		{
			sum += Data[x][y] * flt[y];
		}
		n[x] = sum;
	}
	return Point3D(n[0], n[1], n[2]);
}
Point3D Matrix3x3::Multiply1(const Point3D & p) const
{
	float flt[3] = { p.X, p.Y, p.Z };
	float n[3];
	for (int y = 0; y < 3; y++)
	{
		float sum = 0;
		for (int x = 0; x < 3; x++)
		{
			sum += Data[x][y] * flt[x];
		}
		n[y] = sum;
	}
	return Point3D(n[0], n[1], n[2]);
}



Matrix3x3 Matrix3x3::TransPose() const
{
	Matrix3x3 mat;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			mat.Data[x][y] = Data[y][x];
		}
	}
	return mat;
}



#include <iostream>
void Matrix3x3::ToString() const
{
	for (int i = 0; i < 3; i++)
	{
		std::cout << "[ ";
		for (int j = 0; j < 3; j++)
		{
			if (j != 0) { std::cout << " | "; }
			std::cout << Data[i][j];
		}
		std::cout << " ]";
		std::cout << "\n";
	}
}
