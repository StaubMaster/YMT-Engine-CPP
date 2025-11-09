
#ifndef  MULTI_LINTER_HPP
# define MULTI_LINTER_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/LInter.hpp"
# include "DataStruct/LInter.hpp"

namespace Multiform
{
class LInter : public GBase<Uniform::LInter, ::LInter>
{
	public:
		LInter(std::string name);
};
};

#endif
