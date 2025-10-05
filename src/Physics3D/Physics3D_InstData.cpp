#include "Physics3D/Physics3D_InstData.hpp"



Physics3D_InstData::Physics3D_InstData()
{

}
Physics3D_InstData::Physics3D_InstData(const Trans3D & trans)
{
	Trans = trans;
	Vel = Trans3D();
}
