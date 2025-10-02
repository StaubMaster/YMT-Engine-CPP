
#ifndef  MULTI_RANGE_HPP
# define MULTI_RANGE_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniRange.hpp"
# include "DataStruct/Range.hpp"

namespace Multiform
{
class MultiRange : public GenericMultiformBase<Uniform::Range, Range>
{
	public:
		MultiRange(std::string name);
};
};

#endif
