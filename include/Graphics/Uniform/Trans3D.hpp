
#ifndef  UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "DataDec.hpp"

# include "Graphics/Uniform/Point3D.hpp"
# include "Graphics/Uniform/Angle3D.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Trans3D : public Uniform::GBase<::Trans3D>
{
	private:
		Uniform::Point3D Pos;
		Uniform::Angle3D Rot;

	public:
		Trans3D(std::string name, Shader::Base & shader);

	public:
		void PutData(::Trans3D t) override;
};
};

#endif
