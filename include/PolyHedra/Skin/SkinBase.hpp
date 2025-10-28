#ifndef  POLYHEDRA_SKIN_BASE_HPP
# define POLYHEDRA_SKIN_BASE_HPP

namespace YMT
{
	class PolyHedra;
};

class PolyHedra_SkinBase
{
	protected:
		YMT::PolyHedra & PolyHedra;

	public:
		PolyHedra_SkinBase(YMT::PolyHedra & polyhedra);
		virtual ~PolyHedra_SkinBase();
};

#endif
