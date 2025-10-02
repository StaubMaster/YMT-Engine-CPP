
#ifndef  MULTI_DEPTH_FACTORS_3D_HPP
# define MULTI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniDepthFactors.hpp"
# include "DataStruct/DepthFactors.hpp"

namespace Multiform
{
class MultiDepthFactors : public GenericMultiformBase<Uniform::DepthFactors, DepthFactors>
{
	public:
		MultiDepthFactors(std::string name);
};
};

#endif
