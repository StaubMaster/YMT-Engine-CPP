
#ifndef  MULTI_SIZE_RATIO_2D_HPP
# define MULTI_SIZE_RATIO_2D_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Data/SizeRatio2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

namespace Multiform
{
class SizeRatio2D : public GBase<Uniform::SizeRatio2D, ::SizeRatio2D>
{
	public:
		SizeRatio2D(std::string name);
};
};

#endif

