
#ifndef  SIMPLE_3D_INST_DATA_HPP
# define SIMPLE_3D_INST_DATA_HPP

# include "DataStruct/Trans3D.hpp"

struct Simple3D_InstData
{
	Trans3D Trans;

	public:
		Simple3D_InstData();
		Simple3D_InstData(const Trans3D & trans);
};

#endif
