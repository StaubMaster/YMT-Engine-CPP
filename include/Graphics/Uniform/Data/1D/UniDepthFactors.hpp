
#ifndef  UNI_DEPTH_FACTORS_3D_HPP
# define UNI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

class UniDepthFactors : public GenericUniformBase<DepthFactors>
{
	private:
		int Location;

	public:
		UniDepthFactors(std::string name, BaseShader & shader);

	public:
		void PutData(DepthFactors df) override;
};

# include "DataStruct/DepthFactors.hpp"

class MultiDepthFactors : public GenericMultiformBase<UniDepthFactors, DepthFactors>
{
	public:
		MultiDepthFactors(std::string name);
};

#endif
