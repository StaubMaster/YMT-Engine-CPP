
#ifndef  MULTI_DEPTH_HPP
# define MULTI_DEPTH_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/Depth.hpp"
# include "DataStruct/Depth.hpp"

namespace Multiform
{
class Depth : public GenericMultiformBase<Uniform::Depth, ::Depth>
{
	public:
		Depth(std::string name);
};
};

#endif
