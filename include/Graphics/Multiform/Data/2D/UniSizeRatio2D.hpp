
#ifndef  MULTI_SIZE_RATIO_2D_HPP
# define MULTI_SIZE_RATIO_2D_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"
# include "Graphics/Uniform/Data/2D/UniPoint2D.hpp"
# include "Graphics/Uniform/Data/2D/UniSizeRatio2D.hpp"

class BaseShader;

# include "DataStruct/SizeRatio2D.hpp"

class MultiSizeRatio2D : public GenericMultiformBase<Uniform::SizeRatio2D, SizeRatio2D>
{
	public:
		MultiSizeRatio2D(std::string name);
};

#endif

