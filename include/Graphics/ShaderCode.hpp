
#ifndef SHADER_DIR
# define SHADER_DIR "../media/Shaders/"
#endif

#ifndef SHADER_CODE
# define SHADER_CODE

# include <exception>
# include <string>
# include <fstream>
# include "OpenGL/openGL.h"

class ShaderCode
{
	private:
		int ID;
		std::string Path;

	private:
		ShaderCode(GLenum type, const std::string code, std::string path);
	public:
		~ShaderCode();

		ShaderCode(const ShaderCode & other);
		const ShaderCode & operator = (const ShaderCode & other);

	public:
		void Attach(int ProgramID) const;
		void Detach(int ProgramID) const;

	private:
		void Compile(const std::string code);

		class ECompileLog : public std::exception
		{
			private:
				std::string Log;
				std::string Path;

			public:
				ECompileLog(const std::string log, const std::string path);

			public:
				const char * what() const throw();
		};



	public:
		static ShaderCode FromFile(const std::string & path);

	private:
		class EInvalidFileExtention : std::exception
		{
			private:
				std::string Path;

			public:
				EInvalidFileExtention(const std::string & path);

			public:
				const char * what() const throw();
		};
};

#endif
