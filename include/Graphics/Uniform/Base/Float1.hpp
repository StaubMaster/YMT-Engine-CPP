
#ifndef  UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

class BaseShader;

namespace Uniform
{
class Float1 : public Uniform::FloatN
{
	public:
		Float1(std::string name, BaseShader & shader);
		Float1(int count, std::string name, BaseShader & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
