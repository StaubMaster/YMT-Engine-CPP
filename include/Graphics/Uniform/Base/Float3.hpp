
#ifndef  UNI_FLOAT_3_HPP
# define UNI_FLOAT_3_HPP

# include "Graphics/Uniform/Base/FloatN.hpp"

class BaseShader;

namespace Uniform
{
class Float3 : public Uniform::FloatN
{
	public:
		Float3(std::string name, BaseShader & shader);
		Float3(int count, std::string name, BaseShader & shader);

	public:
		void PutData(const float * val) override;
};
};

#endif
