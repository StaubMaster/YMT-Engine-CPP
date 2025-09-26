
#ifndef BASE_SHADER
# define BASE_SHADER

# include <iostream>
# include <vector>
# include "OpenGL/openGL.h"
# include "ShaderCode.hpp"
# include "Graphics/Uniform/Base/UniformBase.hpp"

class UniformBase;

class BaseShader
{
	private:
		static int CurrentID;

	private:
		int ID;
	public:
		std::vector<UniformBase *> Uniforms;

	protected:
		BaseShader(const ShaderCode * code, int count);
	public:
		virtual ~BaseShader();

	public:
		void Use();
		bool Is() const;

	protected:
		virtual void UniformUpdate() = 0;
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
