
#ifndef  UNI_NEW_Angle_3D_HPP
# define UNI_NEW_Angle_3D_HPP

# include "Abstract.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"

class UniAngle3D : public GenericShaderUniform<Angle3D>
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
