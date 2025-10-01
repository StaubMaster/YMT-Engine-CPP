#include "Data/DataO.hpp"

#include "Data/3D/Point3D.hpp"
#include "Data/3D/Angle3D.hpp"
//#include "Data/3D/Transformation3D.hpp"
#include "Data/3D/Undex3D.hpp"

#include "Data/2D/Point2D.hpp"
//#include "Data/2D/SizeRatio2D.hpp"

//#include "Data/1D/DepthFactors.hpp"
//#include "Data/1D/Range.hpp"
//#include "Data/1D/LInter.hpp"

#include "Data/Color.hpp"
//#include "Data/Depth.hpp"

#include "Data/4D/Point4D.hpp"

#include <iostream>



std::ostream & operator <<(std::ostream & o, const Point2D & val)
{
	o << "( " << val.X << " | " << val.Y << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point3D & val)
{
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " )";
	return o;
}
std::ostream & operator <<(std::ostream & o, const Point4D & val)
{
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " | " << val.W << " )";
	return o;
}

std::ostream & operator <<(std::ostream & o, const Angle3D & val)
{
	o << "( " << val.x << " | " << val.y << " | " << val.z << " )";
	o << "#( " << val.sin_x << " | " << val.sin_y << " | " << val.sin_z << " )";
	o << "#( " << val.cos_x << " | " << val.cos_y << " | " << val.cos_z << " )";
	return o;
}

std::ostream & operator <<(std::ostream & o, const Undex3D & val)
{
	o << "[" << val.X << ":" << val.Y << ":" << val.Z << "]";
	return o;
}

std::ostream & operator <<(std::ostream & o, const Color & val)
{
	o << "(" << " R:" << val.R << " G:" << val.G << " B:" << val.B << " )";
	return o;
}
