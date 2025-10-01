
#ifndef  MULTI_COLOR_HPP
# define MULTI_COLOR_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/UniColor.hpp"

# include "DataDec.hpp"

# include "DataStruct/Color.hpp"

class MultiColor : public GenericMultiformBase<Uniform::Color, Color>
{
	public:
		MultiColor(std::string name);
};

#endif
