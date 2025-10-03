#include "DataStruct/LightSolar.hpp"



LightSolar::LightSolar()
{
	
}
LightSolar::LightSolar(float intensity, Color color, Point3D dir) :
	Base(intensity, color),
	Dir(dir)
{

}
