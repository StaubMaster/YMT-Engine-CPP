
#ifndef  UNI_DEPTH_FACTORS_3D_HPP
# define UNI_DEPTH_FACTORS_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class DepthFactors : public Uniform::GBase<::DepthFactors>
{
	private:
		Uniform::Float1 Location;

	public:
		DepthFactors(std::string name, Shader::Base & shader);

	public:
		void PutData(::DepthFactors val) override;
};
};

#endif
