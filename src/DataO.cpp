#include "DataO.hpp"

#include "DataStruct/Point3D.hpp"
#include "DataStruct/Angle3D.hpp"
//#include "DataStruct/Transformation3D.hpp"
#include "DataStruct/Undex3D.hpp"
#include "DataStruct/AxisBox3D.hpp"

#include "DataStruct/Point2D.hpp"
//#include "DataStruct/SizeRatio2D.hpp"

//#include "DataStruct/DepthFactors.hpp"
//#include "DataStruct/Range.hpp"
//#include "DataStruct/LInter.hpp"

#include "DataStruct/Color.hpp"
//#include "DataStruct/Depth.hpp"

#include "DataStruct/Point4D.hpp"

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
	o << "( " << val.X << " | " << val.Y << " | " << val.Z << " )";
	//o << "#( " << val.sin_x << " | " << val.sin_y << " | " << val.sin_z << " )";
	//o << "#( " << val.cos_x << " | " << val.cos_y << " | " << val.cos_z << " )";
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

std::ostream & operator <<(std::ostream & o, const AxisBox3D & val)
{
	o << "(" << val.Min << " : " << val.Max << " )";
	return o;
}
