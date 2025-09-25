
#ifndef POLYHEDRA_3D_INSTDATA
# define POLYHEDRA_3D_INSTDATA

# include "Abstract.hpp"

struct PolyHedra_3D_InstData
{
	Transformation3D Trans;

	public:
		PolyHedra_3D_InstData();
		PolyHedra_3D_InstData(const Transformation3D & trans);
};

#endif
