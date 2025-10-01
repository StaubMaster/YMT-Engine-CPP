
#ifndef  DEPTH_HPP
# define DEPTH_HPP

# include "DepthFactors.hpp"
# include "Range.hpp"
# include "Color.hpp"

struct Depth
{
	public:
		DepthFactors	Factors;
		Range			Range;
		Color			Color;
};

#endif
