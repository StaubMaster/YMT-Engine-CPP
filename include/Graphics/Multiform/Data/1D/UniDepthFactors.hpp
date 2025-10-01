
#ifndef  MULTI_DEPTH_FACTORS_3D_HPP
# define MULTI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "Graphics/Uniform/Data/1D/UniDepthFactors.hpp"

# include "DataDec.hpp"

class BaseShader;

# include "DataStruct/DepthFactors.hpp"

class MultiDepthFactors : public GenericMultiformBase<Uniform::DepthFactors, DepthFactors>
{
	public:
		MultiDepthFactors(std::string name);
};

#endif
