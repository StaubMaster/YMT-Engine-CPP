
#ifndef  MULTIFORM_BASE_HPP
# define MULTIFORM_BASE_HPP

//# include "Graphics/Shader/BaseShader.hpp"
//# include "Graphics/Uniform/Base/UniformBase.hpp"
//# include "OpenGL/openGL.h"
//# include <iostream>
#include <string>

class BaseShader;
class UniformBase;

class MultiformBase
{
	public:
		std::string Name;

	protected:
		MultiformBase(std::string name);
		~MultiformBase();

	public:
		virtual void FindUniforms(BaseShader ** shaders, int len) = 0;
		virtual void Data_PutUniform(UniformBase * uni_base) = 0;
};

#endif
