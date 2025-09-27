
#ifndef  UNIFORM_BASE_HPP
# define UNIFORM_BASE_HPP

# include <iostream>
# include "OpenGL/openGL.h"
# include "Graphics/Shader/BaseShader.hpp"
# include "Graphics/Uniform/Base/MultiformBase.hpp"

class BaseShader;
class MultiformBase;

class UniformBase
{
	public:
		std::string Name;
		BaseShader & Shader;
		MultiformBase * Uniform;
		bool Changed;

	protected:
		UniformBase(std::string name, BaseShader & shader);
		virtual ~UniformBase();

	public:
		void PutData();
};

#endif
