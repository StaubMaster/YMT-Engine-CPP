
#ifndef  UNI_SIZE_RATIO_2D_HPP
# define UNI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/Point2D.hpp"

class BaseShader;

namespace Uniform
{
class SizeRatio2D : public Uniform::GenericUniformBase<::SizeRatio2D>
{
	private:
		Uniform::Point2D Size;
		Uniform::Point2D Ratio;

	public:
		SizeRatio2D(std::string name, BaseShader & shader);

	public:
		void PutData(::SizeRatio2D sr) override;
};
};

#endif

