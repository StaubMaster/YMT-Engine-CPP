
#ifndef  UNI_RANGE_HPP
# define UNI_RANGE_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDeclare.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Range : public Uniform::GBase<::Range>
{
	private:
		Uniform::Float1 Min;
		Uniform::Float1 Len;
		Uniform::Float1 Max;

	public:
		Range(std::string name, Shader::Base & shader);

	public:
		void PutData(::Range val) override;
};
};

#endif
