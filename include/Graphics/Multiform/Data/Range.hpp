
#ifndef  MULTI_RANGE_HPP
# define MULTI_RANGE_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/Range.hpp"
# include "DataStruct/Range.hpp"

namespace Multiform
{
class Range : public GenericMultiformBase<Uniform::Range, ::Range>
{
	public:
		Range(std::string name);
};
};

#endif
