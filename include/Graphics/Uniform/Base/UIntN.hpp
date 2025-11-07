
#ifndef  UNI_UINT_N_HPP
# define UNI_UINT_N_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

class BaseShader;

namespace Uniform
{
class UIntN : public Uniform::GenericUniformBase<const unsigned int *>
{
	protected:
		int Location;
		int Count;

	public:
		UIntN(int count, std::string name, BaseShader & shader);

	public:
		virtual void PutData(const unsigned int * val) = 0;
		void PutVoid(const void * val);
};
};

#endif
