
#ifndef  UNI_DEPTH_HPP
# define UNI_DEPTH_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/DepthFactors.hpp"
# include "Graphics/Uniform/Range.hpp"
# include "Graphics/Uniform/Color.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Depth : public Uniform::GBase<::Depth>
{
	private:
		Uniform::DepthFactors Factors;
		Uniform::Range Range;
		Uniform::Color Color;

	public:
		Depth(std::string name, Shader::Base & shader);

	public:
		void PutData(::Depth val) override;
};
};

#endif
