
#ifndef  UNI_LIGHT_BASE_HPP
# define UNI_LIGHT_BASE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Base/Float1.hpp"
# include "Graphics/Uniform/Data/Color.hpp"

namespace Shader
{
	class Base;
};

struct LightBase;

namespace Uniform
{
class LightBase : public Uniform::GBase<::LightBase>
{
	private:
		Uniform::Float1 Intensity;
		Uniform::Color Color;

	public:
		LightBase(std::string name, Shader::Base & shader);

	public:
		void PutData(::LightBase val) override;
};
};

#endif
