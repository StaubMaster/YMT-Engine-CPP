
#ifndef  GENERIC_UNIFORM_ARRAY_HPP
# define GENERIC_UNIFORM_ARRAY_HPP

# include "Graphics/Uniform/Base/UniformBase.hpp"
# include "Graphics/Uniform/Base/GenericUniformBase.hpp"

# include <sstream>

class BaseShader;

namespace Uniform
{
template <typename UniformType, typename DataType>
class GenericUniformArray
{
	private:
		unsigned int	Count;
		UniformType **	Uniforms;

	public:
		GenericUniformArray(unsigned int count, std::string name, BaseShader & shader)
		{
			Count = count;
			Uniforms = new UniformType*[Count];
			for (unsigned int i = 0; i < Count; i++)
			{
				std::stringstream ss;
				ss << name << "[" << i << "]";
				std::cout << "Uni:" << ss.str() << "\n";
				Uniforms[i] = new UniformType(ss.str(), shader);
			}
			(void)shader;
		}
		~GenericUniformArray()
		{
			for (unsigned int i = 0; i < Count; i++)
			{
				delete Uniforms[i];
			}
			delete[] Uniforms;
		}

	public:
		void PutData(DataType * data, unsigned int count)
		{
			if (Count < count) { count = Count; }
			for (unsigned int i = 0; i < Count; i++)
			{
				Uniforms[i] -> PutData(data[i]);
			}
		}
};
};

#endif
