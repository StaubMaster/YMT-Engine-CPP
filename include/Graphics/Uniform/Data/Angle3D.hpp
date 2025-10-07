
#ifndef  UNI_Angle_3D_HPP
# define UNI_Angle_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Angle3D : public Uniform::GenericUniformBase<::Angle3D>
{
	private:
		int Location;

	public:
		Angle3D(std::string name, BaseShader & shader);

	public:
		void PutData(::Angle3D p) override;
};
};

#endif
