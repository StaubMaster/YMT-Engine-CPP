
#ifndef  LIGHT_SPOT_HPP
# define LIGHT_SPOT_HPP

# include "LightBase.hpp"
# include "Point3D.hpp"
# include "Range.hpp"

struct LightSpot
{
	public:
		LightBase	Base;
		Point3D		Pos;
		Point3D		Dir;
		Range		Range;

	public:
		LightSpot();
		LightSpot(float intensity, Color color, Point3D pos, Point3D dir, ::Range range);
};

#endif
