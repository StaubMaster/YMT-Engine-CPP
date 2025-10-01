
#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Point3D : public Uniform::GenericUniformBase<::Point3D>
{
	private:
		int Location;

	public:
		Point3D(std::string name, BaseShader & shader);

	public:
		void PutData(::Point3D p) override;
};
};

#endif
