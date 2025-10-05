
#ifndef BASE_SHADER
# define BASE_SHADER

//# include <iostream>
# include <vector>
//# include "OpenGL/openGL.h"
//# include "Graphics/ShaderCode.hpp"
//# include "Graphics/Uniform/Base/UniformBase.hpp"
# include <string>

class ShaderCode;
namespace Uniform
{
	class UniformBase;
};

class BaseShader
{
	private:
		static int CurrentID;

	private:
		int ID;
	public:
		std::vector<Uniform::UniformBase *> Uniforms;

	public:
		BaseShader(const ShaderCode * code, int count);
		virtual ~BaseShader();

	public:
		void Use();
		bool Is() const;

	public:
		void UniformsUpdate();
		int UniformFind(const std::string & name) const;

	private:
		void Compile(const ShaderCode * code, int count);

		class ECompileLog : std::exception
		{
			private:
				std::string Log;
				std::string Text;

			public:
				ECompileLog(const std::string log);

			public:
				const char * what() const throw();
		};
};

#endif
