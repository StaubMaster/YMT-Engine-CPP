
#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/DepthFactors.hpp"
# include "Graphics/Uniform/Data/Range.hpp"
# include "Graphics/Uniform/Data/Color.hpp"

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
