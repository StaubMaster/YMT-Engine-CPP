
#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "Abstract.hpp"
# include "Graphics/Uniform/Data/1D/UniDepthFactors.hpp"
# include "Graphics/Uniform/Data/1D/UniRange.hpp"
# include "Graphics/Uniform/Data/UniColor.hpp"

class UniDepth : public GenericUniformBase<Depth>
{
	private:
		UniDepthFactors Factors;
		UniRange Range;
		UniColor Color;

	public:
		UniDepth(std::string name, BaseShader & shader);

	public:
		void PutData(Depth val) override;
};

class MultiDepth : public GenericMultiformBase<UniDepth, Depth>
{
	public:
		MultiDepth(std::string name);
};

#endif
