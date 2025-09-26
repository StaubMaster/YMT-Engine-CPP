
#ifndef  UNI_NEW_POINT_3D_HPP
# define UNI_NEW_POINT_3D_HPP

# include "Abstract.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"

class UniPoint3D : public GenericShaderUniform<Point3D>
{
	private:
		int Location;

	public:
		UniPoint3D(std::string name, BaseShader & shader);

	public:
		void PutData(Point3D p) override;
};

#endif
