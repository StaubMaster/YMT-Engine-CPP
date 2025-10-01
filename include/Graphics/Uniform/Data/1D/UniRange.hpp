
#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Multiform/Base/GenericMultiformBase.hpp"

# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Range : public Uniform::GenericUniformBase<::Range>
{
	private:
		int LocationMin;
		int LocationLen;
		int LocationMax;

	public:
		Range(std::string name, BaseShader & shader);

	public:
		void PutData(::Range val) override;
};
};

#endif
