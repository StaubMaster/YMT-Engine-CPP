
#ifndef  UNI_NEW_SIZE_RATIO_2D_HPP
# define UNI_NEW_SIZE_RATIO_2D_HPP

# include "Abstract2D/SizeRatio2D.hpp"
# include "Graphics/Uniform/Abstract2D/UniPoint2D.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"
# include "Graphics/Uniform/GenericUniformBase.hpp"

class UniSizeRatio2D : public GenericShaderUniform<SizeRatio2D>
{
	private:
		UniPoint2D Size;
		UniPoint2D Ratio;

	public:
		UniSizeRatio2D(std::string name, BaseShader & shader);

	public:
		void PutData(SizeRatio2D sr) override;
};

class MultiSizeRatio2D : public GenericUniformBase<UniSizeRatio2D, SizeRatio2D>
{
	public:
		MultiSizeRatio2D(std::string name);
};

#endif

