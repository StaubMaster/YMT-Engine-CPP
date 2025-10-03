
#ifndef  UNI_LIGHT_SPOT_HPP
# define UNI_LIGHT_SPOT_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Data/LightBase.hpp"
# include "Graphics/Uniform/Data/Point3D.hpp"
# include "Graphics/Uniform/Data/Range.hpp"

class BaseShader;

struct LightSpot;

namespace Uniform
{
class LightSpot : public Uniform::GenericUniformBase<::LightSpot>
{
	private:
		Uniform::LightBase	Base;
		Uniform::Point3D	Pos;
		Uniform::Point3D	Dir;
		Uniform::Range		Range;

	public:
		LightSpot(std::string name, BaseShader & shader);

	public:
		void PutData(::LightSpot val) override;
};
};

#endif

