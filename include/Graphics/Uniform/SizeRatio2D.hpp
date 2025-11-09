
#ifndef  UNI_SIZE_RATIO_2D_HPP
# define UNI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Point2D.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class SizeRatio2D : public Uniform::GBase<::SizeRatio2D>
{
	private:
		Uniform::Point2D Size;
		Uniform::Point2D Ratio;

	public:
		SizeRatio2D(std::string name, Shader::Base & shader);

	public:
		void PutData(::SizeRatio2D sr) override;
};
};

#endif

