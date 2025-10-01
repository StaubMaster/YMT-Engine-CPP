
#ifndef  UNI_POINT_3D_HPP
# define UNI_POINT_3D_HPP

//# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

# include "Data/DataFore.hpp"

class BaseShader;

class UniPoint3D : public GenericUniformBase<Point3D>
{
	private:
		int Location;

	public:
		UniPoint3D(std::string name, BaseShader & shader);

	public:
		void PutData(Point3D p) override;
};

#endif
