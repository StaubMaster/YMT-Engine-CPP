#ifndef  POLYHEDRA_SKIN_GENERIC_BASE_HPP
# define POLYHEDRA_SKIN_GENERIC_BASE_HPP

# include "SkinBase.hpp"

# include "Miscellaneous/ContainerDynamic.hpp"
//# include "Texture/TextureBase.hpp"

namespace YMT
{
	class PolyHedra;
};

class TextureBase;

template<typename CornerType, typename FaceCornerType, typename FaceType>
class PolyHedra_SkinGenericBase : public PolyHedra_SkinBase
{
	public:
		ContainerDynamic<CornerType>	Corners;
		ContainerDynamic<FaceType>		Faces;

	public:
		PolyHedra_SkinGenericBase(YMT::PolyHedra & polyhedra) :
			PolyHedra_SkinBase(polyhedra)
			{ }
		virtual ~PolyHedra_SkinGenericBase() { }

	public:
		void Done() override
		{
			Corners.Trim();
			Faces.Trim();
		}

		void Insert_Face3(FaceCornerType corn0, FaceCornerType corn1, FaceCornerType corn2)
		{
			Faces.Insert(FaceType(corn0, corn1, corn2));
		}
		void Insert_Face4(FaceCornerType corn0, FaceCornerType corn1, FaceCornerType corn2, FaceCornerType corn3)
		{
			Insert_Face3(corn0, corn1, corn2);
			Insert_Face3(corn2, corn1, corn3);
		}
};

#endif
