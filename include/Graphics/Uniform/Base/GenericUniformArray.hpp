
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
	public:
		const unsigned int	Limit;
	private:
		UniformType **	Uniforms;

	public:
		GenericUniformArray(unsigned int count, std::string name, BaseShader & shader) :
			Limit(count)
		{
			Uniforms = new UniformType*[Limit];
			for (unsigned int i = 0; i < Limit; i++)
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
			for (unsigned int i = 0; i < Limit; i++)
			{
				delete Uniforms[i];
			}
			delete[] Uniforms;
		}

	public:
		UniformType & operator[](unsigned int index)
		{
			return *(Uniforms[index]);
		}

	public:
		void PutData(DataType * data, unsigned int count)
		{
			if (Limit < count) { count = Limit; }
			for (unsigned int i = 0; i < count; i++)
			{
				Uniforms[i] -> PutData(data[i]);
			}
		}
};
};

#endif
