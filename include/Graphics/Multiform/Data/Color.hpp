
#ifndef  MULTI_COLOR_HPP
# define MULTI_COLOR_HPP

# include "Graphics/Multiform/Base/GBase.hpp"
# include "Graphics/Uniform/Data/Color.hpp"
# include "DataStruct/Color.hpp"

namespace Multiform
{
class Color : public GBase<Uniform::Color, ::Color>
{
	public:
		Color(std::string name);
};
};

#endif
