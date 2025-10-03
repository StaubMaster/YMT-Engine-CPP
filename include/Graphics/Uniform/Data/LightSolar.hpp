
#ifndef  UNI_LIGHT_SOLAR_HPP
# define UNI_LIGHT_SOLAR_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/LightBase.hpp"
# include "Graphics/Uniform/Data/Point3D.hpp"

class BaseShader;

struct LightSolar;

namespace Uniform
{
class LightSolar : public Uniform::GenericUniformBase<::LightSolar>
{
	private:
		Uniform::LightBase	Base;
		Uniform::Point3D	Dir;

	public:
		LightSolar(std::string name, BaseShader & shader);

	public:
		void PutData(::LightSolar val) override;
};
};

#endif

