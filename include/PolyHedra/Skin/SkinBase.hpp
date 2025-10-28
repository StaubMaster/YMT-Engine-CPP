#ifndef  POLYHEDRA_SKIN_BASE_HPP
# define POLYHEDRA_SKIN_BASE_HPP

# include "Miscellaneous/ContainerDynamic.hpp"

namespace YMT
{
	class PolyHedra;
};

template<typename CornerType, typename FaceCornerType, typename FaceType>
class PolyHedra_SkinBase
{
	protected:
		YMT::PolyHedra & PolyHedra;
	public:
		ContainerDynamic<CornerType>	Corners;
		ContainerDynamic<FaceType>		Faces;

	public:
		PolyHedra_SkinBase(YMT::PolyHedra & polyhedra) : PolyHedra(polyhedra) { }
		virtual ~PolyHedra_SkinBase() { }

	public:
		void Done()
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
