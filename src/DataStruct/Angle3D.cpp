#include "DataStruct/Angle3D.hpp"
#include "DataStruct/Point3D.hpp"

#include <math.h>



Angle3D::Angle3D() : x(0), y(0), z(0)
{
	sin_x = sin(x);
	sin_y = sin(y);
	sin_z = sin(z);
	cos_x = cos(x);
	cos_y = cos(y);
	cos_z = cos(z);
}
Angle3D::Angle3D(float x, float y, float z) : x(x), y(y), z(z)
{
	sin_x = sin(x);
	sin_y = sin(y);
	sin_z = sin(z);
	cos_x = cos(x);
	cos_y = cos(y);
	cos_z = cos(z);
}
Angle3D::~Angle3D()
{

}



Angle3D::Angle3D(const Angle3D & other) : x(other.x), y(other.y), z(other.z)
{
	sin_x = sin(x);
	sin_y = sin(y);
	sin_z = sin(z);
	cos_x = cos(x);
	cos_y = cos(y);
	cos_z = cos(z);
}
const Angle3D & Angle3D::operator =(const Angle3D & other)
{
	this -> x = other.x;
	this -> y = other.y;
	this -> z = other.z;
	this -> sin_x = other.sin_x;
	this -> sin_y = other.sin_y;
	this -> sin_z = other.sin_z;
	this -> cos_x = other.cos_x;
	this -> cos_y = other.cos_y;
	this -> cos_z = other.cos_z;
	return *this;
}



void Angle3D::UpdateSinCos()
{
	sin_x = sin(x);
	sin_y = sin(y);
	sin_z = sin(z);
	cos_x = cos(x);
	cos_y = cos(y);
	cos_z = cos(z);
}
void Angle3D::ChangeX(float x)
{
	this -> x = x;
	sin_x = sin(x);
	cos_x = cos(x);
}
void Angle3D::ChangeY(float y)
{
	this -> y = y;
	sin_y = sin(y);
	cos_y = cos(y);
}
void Angle3D::ChangeZ(float z)
{
	this -> z = z;
	sin_z = sin(z);
	cos_z = cos(z);
}



Point3D	Angle3D::rotate_fore(Point3D p) const
{
	rotate(p.X, p.Z, cos_x, sin_x);
	rotate(p.Y, p.Z, cos_y, sin_y);
	rotate(p.Y, p.X, cos_z, sin_z);
	return (p);
}
Point3D	Angle3D::rotate_back(Point3D p) const
{
	rotate(p.X, p.Y, cos_z, sin_z);
	rotate(p.Z, p.Y, cos_y, sin_y);
	rotate(p.Z, p.X, cos_x, sin_x);
	return (p);
}

Angle3D	Angle3D::rotate_fore(Angle3D a) const
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
}
Angle3D	Angle3D::rotate_back(Angle3D a) const
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
}


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
