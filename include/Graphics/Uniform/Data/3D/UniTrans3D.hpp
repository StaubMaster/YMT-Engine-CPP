
#ifndef  UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "Abstract.hpp"
# include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
# include "Graphics/Uniform/Data/3D/UniAngle3D.hpp"

class UniTrans3D : public GenericUniformBase<Transformation3D>
{
	private:
		UniPoint3D Pos;
		UniAngle3D Rot;

	public:
		UniTrans3D(std::string name, BaseShader & shader);

	public:
		void PutData(Transformation3D t) override;
};

class MultiTrans3D : public GenericMultiformBase<UniTrans3D, Transformation3D>
{
	public:
		MultiTrans3D(std::string name);
};

#endif
