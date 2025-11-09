
#ifndef  UNI_FLOAT_N_HPP
# define UNI_FLOAT_N_HPP

# include "Graphics/Uniform/Base/GBase.hpp"

namespace Shader
{
	class Base;
};

namespace Uniform
{
class FloatN : public Uniform::GBase<const float *>
{
	protected:
		int Location;
		int Count;

	public:
		FloatN(int count, std::string name, Shader::Base & shader);

	public:
		virtual void PutData(const float * val) = 0;
		void PutVoid(const void * val);
};
};

#endif
