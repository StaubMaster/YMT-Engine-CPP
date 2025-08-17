
#ifndef BASE_SHADER
# define BASE_SHADER

# include <iostream>
# include "../../OpenGL/openGL.h"
# include "ShaderCode.hpp"

class BaseShader
{
	private:
		int ID;

	protected:
		BaseShader(const ShaderCode * code, int count);
	public:
		~BaseShader();

	public:
		void Use();
		bool Is() const;

	protected:
		//virtual void UpdateUniform();

	public:
		int UniformFind(const std::string & name) const;

	private:
		void Compile(const ShaderCode * code, int count);

		class ECompileLog : std::exception
		{
			private:
				std::string Log;

			public:
				ECompileLog(const std::string log);

			public:
				const char * what() const throw();
		};
};

#endif
