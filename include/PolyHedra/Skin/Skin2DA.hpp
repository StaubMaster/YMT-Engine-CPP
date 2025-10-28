#ifndef  POLYHEDRA_SKIN_2DA_HPP
# define POLYHEDRA_SKIN_2DA_HPP

# include "PolyHedra/Skin/SkinBase.hpp"
# include "PolyHedra/Skin/Skin2D_Data.hpp"
# include "Texture2DArray.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"

# include "DataStruct/Point2D.hpp"
# include "DataStruct/Point3D.hpp"

class PolyHedra_Skin2DA : public PolyHedra_SkinBase<Skin2DCorner, Skin2DFaceCorner, Skin2DFace>
{
	public:
		PolyHedra_Skin2DA(YMT::PolyHedra & polyhedra);
		~PolyHedra_Skin2DA();
};

#endif
