
#ifndef  UNI_LIGHT_SOLAR_HPP
# define UNI_LIGHT_SOLAR_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/LightBase.hpp"
# include "Graphics/Uniform/Point3D.hpp"

namespace Shader
{
	class Base;
};

struct LightSolar;

namespace Uniform
{
class LightSolar : public Uniform::GBase<::LightSolar>
{
	private:
		Uniform::LightBase	Base;
		Uniform::Point3D	Dir;

	public:
		LightSolar(std::string name, Shader::Base & shader);

	public:
		void PutData(::LightSolar val) override;
};
};

#endif

