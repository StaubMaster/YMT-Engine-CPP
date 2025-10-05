
#ifndef  PHYSICS_3D_INST_DATA_HPP
# define PHYSICS_3D_INST_DATA_HPP

# include "DataStruct/Trans3D.hpp"

struct Physics3D_InstData
{
	Trans3D Trans;
	Trans3D Vel;

	public:
		Physics3D_InstData();
		Physics3D_InstData(const Trans3D & trans);
};

#endif
