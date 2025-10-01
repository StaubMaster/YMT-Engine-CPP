
#ifndef  UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"
# include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
# include "Graphics/Uniform/Data/3D/UniAngle3D.hpp"

class BaseShader;

namespace Uniform
{
class Trans3D : public Uniform::GenericUniformBase<::Trans3D>
{
	private:
		Uniform::Point3D Pos;
		Uniform::Angle3D Rot;

	public:
		Trans3D(std::string name, BaseShader & shader);

	public:
		void PutData(::Trans3D t) override;
};
};

#endif
