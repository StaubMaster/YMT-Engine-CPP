
#ifndef  UNI_FLOAT_1_HPP
# define UNI_FLOAT_1_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

class BaseShader;

namespace Uniform
{
class Float1 : public Uniform::GenericUniformBase<float *>
{
	private:
		int Count;
		int Location;

	public:
		Float1(int count, std::string name, BaseShader & shader);

	public:
		void PutData(float * val) override;
};
};

#endif
