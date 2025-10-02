
#ifndef  MULTI_TRANS_3D_HPP
# define MULTI_TRANS_3D_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/Trans3D.hpp"
# include "DataStruct/Trans3D.hpp"

namespace Multiform
{
class Trans3D : public GenericMultiformBase<Uniform::Trans3D, ::Trans3D>
{
	public:
		Trans3D(std::string name);
};
};

#endif
