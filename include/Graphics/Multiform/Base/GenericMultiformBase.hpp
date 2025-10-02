
#ifndef  GENERIC_MULTIFORM_BASE_HPP
# define GENERIC_MULTIFORM_BASE_HPP

# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Multiform/Base/MultiformBase.hpp"
# include "Graphics/Uniform/Base/UniformBase.hpp"

# include <typeinfo>

namespace Multiform
{
template <typename UniformType, typename DataType>
class GenericMultiformBase : public MultiformBase
{
	public:
		UniformType ** Uniforms;
		int UniformsCount;
		DataType Data;

	public:
		GenericMultiformBase(std::string name) :
			MultiformBase(name)
		{
			Uniforms = NULL;
			UniformsCount = 0;
		}
		virtual ~GenericMultiformBase()
		{
			if (Uniforms != NULL)
			{
				delete [] Uniforms;
			}
		}

	public:
		void FindUniforms(BaseShader ** shaders, int count) override
		{
			UniformType ** uniforms = new UniformType*[count];
			int c = 0;

			//std::cout << "Shader.Count " << count << "\n";
			for (int s = 0; s < count; s++)
			{
				//std::cout << "Shader[" << s << "]\n";
				//std::cout << "Uniform.Count " << ((int)shaders[s] -> Uniforms.size()) << "\n";
				for (int u = 0; u < (int)shaders[s] -> Uniforms.size(); u++)
				{
					//std::cout << "Uniform[" << u << "]\n";
					Uniform::UniformBase * uni = shaders[s] -> Uniforms[u];
					//std::cout << "Uniform '" << (this -> Name) << "'\n";
					//std::cout << "Uniform '" << (uni -> Name) << "'\n";
					//std::cout << "Type: " << typeid(UniformType).name() << "\n";
					//std::cout << "Type: " << typeid(*uni).name() << "\n";
					if (uni -> Name == this -> Name)
					{
						//std::cout << "Uniform Name matches\n";
						if (typeid(*uni) == typeid(UniformType))
						{
							//std::cout << "Uniform Type matches\n";
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

		void Data_PutUniform(Uniform::UniformBase * uni_base)
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
