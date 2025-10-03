
#ifndef  UNI_LIGHT_BASE_HPP
# define UNI_LIGHT_BASE_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/Float1.hpp"
# include "Graphics/Uniform/Data/Color.hpp"

class BaseShader;

struct LightBase;

namespace Uniform
{
class LightBase : public Uniform::GenericUniformBase<::LightBase>
{
	private:
		Uniform::Float1 Intensity;
		Uniform::Color Color;

	public:
		LightBase(std::string name, BaseShader & shader);

	public:
		void PutData(::LightBase val) override;
};
};

#endif
