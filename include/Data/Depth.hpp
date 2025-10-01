
#ifndef  DEPTH_HPP
# define DEPTH_HPP

# include "1D/DepthFactors.hpp"
# include "1D/Range.hpp"
# include "Color.hpp"

struct Depth
{
	public:
		DepthFactors	Factors;
		Range			Range;
		Color			Color;
};

#endif
