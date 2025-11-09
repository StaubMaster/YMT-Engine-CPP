
#ifndef  UNI_FLOAT_2_HPP
# define UNI_FLOAT_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float2 : public Uniform::FloatN
{
	public:
		Float2(std::string name, Shader::Base & shader);
		Float2(int count, std::string name, Shader::Base & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
