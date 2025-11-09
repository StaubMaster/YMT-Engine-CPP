
#ifndef  MULTI_DEPTH_HPP
# define MULTI_DEPTH_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Depth.hpp"
# include "DataStruct/Depth.hpp"

namespace Multiform
{
class Depth : public GBase<Uniform::Depth, ::Depth>
{
	public:
		Depth(std::string name);
};
};

#endif
