
#ifndef  UNI_FLOAT_2_HPP
# define UNI_FLOAT_2_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

class BaseShader;

namespace Uniform
{
class Float2 : public Uniform::FloatN
{
	public:
		Float2(std::string name, BaseShader & shader);
		Float2(int count, std::string name, BaseShader & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
