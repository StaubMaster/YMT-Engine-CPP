
#ifndef  UNI_NEW_TRANS_3D_HPP
# define UNI_NEW_TRANS_3D_HPP

# include "Abstract.hpp"
# include "Graphics/BaseShader.hpp"
# include "Graphics/Uniform/GenericShaderUniform.hpp"
# include "Graphics/Uniform/GenericUniformBase.hpp"
# include "Graphics/Uniform/Abstract3D/UniPoint3D.hpp"
# include "Graphics/Uniform/Abstract3D/UniAngle3D.hpp"

class UniTrans3D : public GenericShaderUniform<Transformation3D>
{
	private:
		UniPoint3D Pos;
		UniAngle3D Rot;

	public:
		UniTrans3D(std::string name, BaseShader & shader);

	public:
		void PutData(Transformation3D t) override;
};

class MultiTrans3D : public GenericUniformBase<UniTrans3D, Transformation3D>
{
	public:
		MultiTrans3D(std::string name);
};

#endif
