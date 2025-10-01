
#ifndef  MULTI_DEPTH_HPP
# define MULTI_DEPTH_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"
# include "Graphics/Uniform/Data/1D/UniDepthFactors.hpp"
# include "Graphics/Uniform/Data/1D/UniRange.hpp"
# include "Graphics/Uniform/Data/UniColor.hpp"
# include "Graphics/Uniform/Data/UniDepth.hpp"

# include "DataStruct/Depth.hpp"

class MultiDepth : public GenericMultiformBase<Uniform::Depth, Depth>
{
	public:
		MultiDepth(std::string name);
};

#endif
