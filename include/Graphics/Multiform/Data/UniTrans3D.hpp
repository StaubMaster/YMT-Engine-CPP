
#ifndef  MULTI_TRANS_3D_HPP
# define MULTI_TRANS_3D_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniTrans3D.hpp"
# include "DataStruct/Trans3D.hpp"

namespace Multiform
{
class MultiTrans3D : public GenericMultiformBase<Uniform::Trans3D, Trans3D>
{
	public:
		MultiTrans3D(std::string name);
};
};

#endif
