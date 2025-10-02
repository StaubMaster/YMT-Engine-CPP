
#ifndef  MULTI_SIZE_RATIO_2D_HPP
# define MULTI_SIZE_RATIO_2D_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniSizeRatio2D.hpp"
# include "DataStruct/SizeRatio2D.hpp"

namespace Multiform
{
class MultiSizeRatio2D : public GenericMultiformBase<Uniform::SizeRatio2D, SizeRatio2D>
{
	public:
		MultiSizeRatio2D(std::string name);
};
};

#endif

