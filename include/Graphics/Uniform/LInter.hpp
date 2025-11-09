
#ifndef  UNI_LINTER_HPP
# define UNI_LINTER_HPP

# include "Graphics/Uniform/Base/GBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDec.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class LInter : public Uniform::GBase<::LInter>
{
	private:
		Uniform::Float1 T0;
		Uniform::Float1 T1;

	public:
		LInter(std::string name, Shader::Base & shader);

	public:
		void PutData(::LInter val) override;
};
};

#endif
