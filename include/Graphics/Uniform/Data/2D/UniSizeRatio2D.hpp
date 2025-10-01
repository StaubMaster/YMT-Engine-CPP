
#ifndef  UNI_SIZE_RATIO_2D_HPP
# define UNI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"
# include "Graphics/Uniform/Data/2D/UniPoint2D.hpp"

class BaseShader;

class UniSizeRatio2D : public GenericUniformBase<SizeRatio2D>
{
	private:
		UniPoint2D Size;
		UniPoint2D Ratio;

	public:
		UniSizeRatio2D(std::string name, BaseShader & shader);

	public:
		void PutData(SizeRatio2D sr) override;
};

# include "DataStruct/SizeRatio2D.hpp"

class MultiSizeRatio2D : public GenericMultiformBase<UniSizeRatio2D, SizeRatio2D>
{
	public:
		MultiSizeRatio2D(std::string name);
};

#endif

