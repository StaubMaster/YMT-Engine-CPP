
#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class Range : public Uniform::GenericUniformBase<::Range>
{
	private:
		Uniform::Float1 Min;
		Uniform::Float1 Len;
		Uniform::Float1 Max;

	public:
		Range(std::string name, BaseShader & shader);

	public:
		void PutData(::Range val) override;
};
};

#endif
