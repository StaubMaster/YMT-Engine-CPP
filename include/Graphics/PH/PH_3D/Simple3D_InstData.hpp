
#ifndef  SIMPLE_3D_INST_DATA_HPP
# define SIMPLE_3D_INST_DATA_HPP

# include "Abstract.hpp"

struct Simple3D_InstData
{
	Transformation3D Trans;

	public:
		Simple3D_InstData();
		Simple3D_InstData(const Transformation3D & trans);
};

#endif
