
#ifndef  POLYHEDRA_3D_INST_DATA
# define POLYHEDRA_3D_INST_DATA

# include "Abstract.hpp"

struct PolyHedra_3D_InstData
{
	Transformation3D Trans;

	public:
		PolyHedra_3D_InstData();
		PolyHedra_3D_InstData(const Transformation3D & trans);
};

#endif
