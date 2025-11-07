
#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/Float3.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Point3D : public Uniform::GenericUniformBase<::Point3D>
{
	private:
		Uniform::Float3 Location;

	public:
		Point3D(std::string name, BaseShader & shader);

	public:
		void PutData(::Point3D p) override;
};
};

#endif
