
#ifndef  UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float1 : public Uniform::FloatN
{
	public:
		Float1(std::string name, Shader::Base & shader);
		Float1(int count, std::string name, Shader::Base & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
