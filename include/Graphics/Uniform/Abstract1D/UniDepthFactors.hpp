
#ifndef  UNI_NEW_DEPTH_FACTORS_3D_HPP
# define UNI_NEW_DEPTH_FACTORS_3D_HPP

# include "Abstract1D/DepthFactors.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"
# include "Graphics/Uniform/GenericUniformBase.hpp"

class UniDepthFactors : public GenericShaderUniform<DepthFactors>
{
	private:
		int Location;

	public:
		UniDepthFactors(std::string name, BaseShader & shader);

	public:
		void PutData(DepthFactors df) override;
};

class MultiDepthFactors : public GenericUniformBase<UniDepthFactors, DepthFactors>
{
	public:
		MultiDepthFactors(std::string name);
};

#endif
