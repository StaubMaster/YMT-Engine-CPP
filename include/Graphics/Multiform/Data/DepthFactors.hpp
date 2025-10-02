
#ifndef  MULTI_DEPTH_FACTORS_3D_HPP
# define MULTI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/DepthFactors.hpp"
# include "DataStruct/DepthFactors.hpp"

namespace Multiform
{
class DepthFactors : public GenericMultiformBase<Uniform::DepthFactors, ::DepthFactors>
{
	public:
		DepthFactors(std::string name);
};
};

#endif
