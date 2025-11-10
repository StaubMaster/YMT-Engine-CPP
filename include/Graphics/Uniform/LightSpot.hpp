
#ifndef  UNI_LIGHT_SPOT_HPP
# define UNI_LIGHT_SPOT_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDeclare.hpp"

# include "Graphics/Uniform/LightBase.hpp"
# include "Graphics/Uniform/Point3D.hpp"
# include "Graphics/Uniform/Range.hpp"

namespace Shader
{
	class Base;
};

struct LightSpot;

namespace Uniform
{
class LightSpot : public Uniform::GBase<::LightSpot>
{
	private:
		Uniform::LightBase	Base;
		Uniform::Point3D	Pos;
		Uniform::Point3D	Dir;
		Uniform::Range		Range;

	public:
		LightSpot(std::string name, Shader::Base & shader);

	public:
		void PutData(::LightSpot val) override;
};
};

#endif

