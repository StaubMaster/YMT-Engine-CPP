
#ifndef  MULTI_DEPTH_HPP
# define MULTI_DEPTH_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniDepth.hpp"
# include "DataStruct/Depth.hpp"

namespace Multiform
{
class MultiDepth : public GenericMultiformBase<Uniform::Depth, Depth>
{
	public:
		MultiDepth(std::string name);
};
};

#endif
