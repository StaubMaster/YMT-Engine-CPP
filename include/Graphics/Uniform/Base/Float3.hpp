
#ifndef  UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class Float3 : public Uniform::FloatN
{
	public:
		Float3(std::string name, Shader::Base & shader);
		Float3(int count, std::string name, Shader::Base & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
