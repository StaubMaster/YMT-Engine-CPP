
#ifndef  UNI_UINT_1_HPP
# define UNI_UINT_1_HPP

# include "Graphics/Uniform/Base/UIntN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class UInt1 : public Uniform::UIntN
{
	public:
		UInt1(std::string name, Shader::Base & shader);
		UInt1(int count, std::string name, Shader::Base & shader);

	public:
		void PutData(const unsigned int * val) override;
};
};

#endif
