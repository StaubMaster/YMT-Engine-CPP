
#ifndef  MULTI_TRANS_3D_HPP
# define MULTI_TRANS_3D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"
# include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
# include "Graphics/Uniform/Data/3D/UniAngle3D.hpp"
# include "Graphics/Uniform/Data/3D/UniTrans3D.hpp"

# include "DataStruct/Trans3D.hpp"

class MultiTrans3D : public GenericMultiformBase<Uniform::Trans3D, Trans3D>
{
	public:
		MultiTrans3D(std::string name);
};

#endif
