
#ifndef  UNI_Angle_3D_HPP
# define UNI_Angle_3D_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

# include "Abstract.hpp"

class UniAngle3D : public GenericUniformBase<Angle3D>
{
	private:
		int LocationSin;
		int LocationCos;

	public:
		UniAngle3D(std::string name, BaseShader & shader);

	public:
		void PutData(Angle3D p) override;
};

#endif
