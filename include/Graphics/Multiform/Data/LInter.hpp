
#ifndef  MULTI_LINTER_HPP
# define MULTI_LINTER_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/LInter.hpp"
# include "DataStruct/LInter.hpp"

namespace Multiform
{
class LInter : public GenericMultiformBase<Uniform::LInter, ::LInter>
{
	public:
		LInter(std::string name);
};
};

#endif
