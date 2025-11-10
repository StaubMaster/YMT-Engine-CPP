
#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float3.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Point3D : public Uniform::GBase<::Point3D>
{
	private:
		Uniform::Float3 Location;

	public:
		Point3D(std::string name, Shader::Base & shader);

	public:
		void PutData(::Point3D p) override;
};
};

#endif
