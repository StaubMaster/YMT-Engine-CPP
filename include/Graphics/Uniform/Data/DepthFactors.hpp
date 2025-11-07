
#ifndef  UNI_DEPTH_FACTORS_3D_HPP
# define UNI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class DepthFactors : public Uniform::GenericUniformBase<::DepthFactors>
{
	private:
		Uniform::Float1 Location;

	public:
		DepthFactors(std::string name, BaseShader & shader);

	public:
		void PutData(::DepthFactors val) override;
};
};

#endif
