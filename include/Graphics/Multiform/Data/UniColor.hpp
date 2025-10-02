
#ifndef  MULTI_COLOR_HPP
# define MULTI_COLOR_HPP

# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniColor.hpp"
# include "DataStruct/Color.hpp"

namespace Multiform
{
class MultiColor : public GenericMultiformBase<Uniform::Color, Color>
{
	public:
		MultiColor(std::string name);
};
};

#endif
