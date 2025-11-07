
#ifndef  UNI_LINTER_HPP
# define UNI_LINTER_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "Graphics/Uniform/Base/Float1.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class LInter : public Uniform::GenericUniformBase<::LInter>
{
	private:
		Uniform::Float1 T0;
		Uniform::Float1 T1;

	public:
		LInter(std::string name, BaseShader & shader);

	public:
		void PutData(::LInter val) override;
};
};

#endif
