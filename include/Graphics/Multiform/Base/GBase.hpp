
#ifndef  GENERIC_MULTIFORM_BASE_HPP
# define GENERIC_MULTIFORM_BASE_HPP

# include "Graphics/Shader/Base.hpp"
# include "Graphics/Multiform/Base/Base.hpp"
# include "Graphics/Uniform/Base/Base.hpp"

# include <typeinfo>

namespace Multiform
{
template <typename UniformType, typename DataType>
class GBase : public Base
{
	public:
		UniformType ** Uniforms;
		int UniformsCount;
		DataType Data;

	public:
		GBase(std::string name) :
			Base(name)
		{
			Uniforms = NULL;
			UniformsCount = 0;
		}
		virtual ~GBase()
		{
			if (Uniforms != NULL)
			{
				delete [] Uniforms;
			}
		}

	public:
		void FindUniforms(Shader::Base ** shaders, int count) override
		{
			UniformType ** uniforms = new UniformType*[count];
			int c = 0;

			for (int s = 0; s < count; s++)
			{
				for (int u = 0; u < (int)shaders[s] -> Uniforms.size(); u++)
				{
					Uniform::Base * uni = shaders[s] -> Uniforms[u];
					if (uni -> Name == this -> Name)
					{
						if (typeid(*uni) == typeid(UniformType))
						{
							uni -> Uniform = this;
							uniforms[c] = (UniformType*)(uni);
							c++;
						}
						else
						{
							//std::cout << "GenericUniformBase: Uniform Type does not match\n";
						}
					}
				}
			}

			Uniforms = new UniformType*[c];
			for (int i = 0; i < c; i++)
			{
				Uniforms[i] = uniforms[i];
			}
			UniformsCount = c;
			delete [] uniforms;
		}

		void Data_PutUniform(Uniform::Base * uni_base) override
		{
			UniformType * uni = (UniformType*)uni_base;
			uni -> PutData(Data);
			uni -> Changed = false;
		}
		void ChangeData(DataType data)
		{
			//std::cout << "UniformsCount " << UniformsCount << "\n";
			Data = data;
			for (int i = 0; i < UniformsCount; i++)
			{
				if (Uniforms[i] -> Shader.Is())
				{
					//std::cout << "Shader[" << i << "].Is()\n";
					Data_PutUniform(Uniforms[i]);
				}
				else
				{
					Uniforms[i] -> Changed = true;
				}
			}
		}
};
};

#endif
