
#ifndef  MULTI_RANGE_HPP
# define MULTI_RANGE_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"
# include "Graphics/Uniform/Data/1D/UniRange.hpp"

# include "DataDec.hpp"

class BaseShader;

# include "DataStruct/Range.hpp"

class MultiRange : public GenericMultiformBase<Uniform::Range, Range>
{
	public:
		MultiRange(std::string name);
};

#endif
