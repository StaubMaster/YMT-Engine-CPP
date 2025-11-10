
#ifndef  UNI_Angle_3D_HPP
# define UNI_Angle_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Angle3D : public Uniform::GBase<::Angle3D>
{
	private:
		int Location;

	public:
		Angle3D(std::string name, Shader::Base & shader);

	public:
		void PutData(::Angle3D p) override;
};
};

#endif
