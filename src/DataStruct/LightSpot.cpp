#include "DataStruct/LightSpot.hpp"



LightSpot::LightSpot()
{
	
}
LightSpot::LightSpot(float intensity, Color color, Point3D pos, Point3D dir, ::Range range) :
	Base(intensity, color),
	Pos(pos),
	Dir(dir),
	Range(range)
{

}
