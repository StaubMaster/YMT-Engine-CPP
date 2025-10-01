
#ifndef  UNI_TRANS_3D_HPP
# define UNI_TRANS_3D_HPP

//# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/GenericMultiformBase.hpp"

# include "Data/DataFore.hpp"
# include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
# include "Graphics/Uniform/Data/3D/UniAngle3D.hpp"

class BaseShader;

class UniTrans3D : public GenericUniformBase<Trans3D>
{
	private:
		UniPoint3D Pos;
		UniAngle3D Rot;

	public:
		UniTrans3D(std::string name, BaseShader & shader);

	public:
		void PutData(Trans3D t) override;
};

# include "Data/3D/Trans3D.hpp"

class MultiTrans3D : public GenericMultiformBase<UniTrans3D, Trans3D>
{
	public:
		MultiTrans3D(std::string name);
};

#endif
