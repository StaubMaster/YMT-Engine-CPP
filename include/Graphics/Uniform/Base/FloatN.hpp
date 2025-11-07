
#ifndef  UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

class BaseShader;

namespace Uniform
{
class FloatN : public Uniform::GenericUniformBase<const float *>
{
	protected:
		int Location;
		int Count;

	public:
		FloatN(int count, std::string name, BaseShader & shader);

	public:
		virtual void PutData(const float * val) = 0;
		void PutVoid(const void * val);
};
};

#endif
