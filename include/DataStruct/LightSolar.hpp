
#ifndef  LIGHT_SOLAR_HPP
# define LIGHT_SOLAR_HPP

# include "LightBase.hpp"
# include "Point3D.hpp"

struct LightSolar
{
	public:
		LightBase	Base;
		Point3D		Dir;

	public:
		LightSolar();
		LightSolar(float intensity, Color color, Point3D dir);
};

#endif
