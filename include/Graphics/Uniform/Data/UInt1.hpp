
#ifndef  UNI_UINT_1_HPP
# define UNI_UINT_1_HPP

# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

class BaseShader;

namespace Uniform
{
class UInt1 : public Uniform::GenericUniformBase<unsigned int *>
{
	private:
		int Count;
		int Location;

	public:
		UInt1(int count, std::string name, BaseShader & shader);

	public:
		void PutData(unsigned int * val) override;
};
};

#endif
