
#ifndef  UNI_LINTER_HPP
# define UNI_LINTER_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"
# include "DataDec.hpp"

class BaseShader;

namespace Uniform
{
class LInter : public Uniform::GenericUniformBase<::LInter>
{
	private:
		int LocationT0;
		int LocationT1;

	public:
		LInter(std::string name, BaseShader & shader);

	public:
		void PutData(::LInter val) override;
};
};

#endif
