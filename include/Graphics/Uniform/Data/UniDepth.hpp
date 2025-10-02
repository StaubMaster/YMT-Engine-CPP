
#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/UniDepthFactors.hpp"
# include "Graphics/Uniform/Data/UniRange.hpp"
# include "Graphics/Uniform/Data/UniColor.hpp"

class BaseShader;

namespace Uniform
{
class Depth : public Uniform::GenericUniformBase<::Depth>
{
	private:
		Uniform::DepthFactors Factors;
		Uniform::Range Range;
		Uniform::Color Color;

	public:
		Depth(std::string name, BaseShader & shader);

	public:
		void PutData(::Depth val) override;
};
};

#endif
