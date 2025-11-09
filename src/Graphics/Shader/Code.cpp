#include "Graphics/Shader/Code.hpp"
#include "FileContext.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



Shader::Code::Code(GLenum type, const std::string code, const std::string path)
{
	Path = path;
	ID = glCreateShader(type);
	Debug::Log << "++++ Shader::Code " << ID << Debug::Done;
	Compile(code);
}
Shader::Code::~Code()
{
	Debug::Log << "---- Shader::Code " << ID << Debug::Done;
	glDeleteShader(ID);
}



int Shader::Code::getID() const
{
	return ID;
}

void Shader::Code::Attach(int ProgramID) const
{
	glAttachShader(ProgramID, ID);
}
void Shader::Code::Detach(int ProgramID) const
{
	glAttachShader(ProgramID, ID);
}

void Shader::Code::Compile(const std::string code)
{
	Debug::Log << "Compiling Shader::Code " << ID << " ..." << Debug::Done;
	const char * arr[1] = {
		code.c_str(),
	};
	glShaderSource(ID, 1, arr, NULL);
	glCompileShader(ID);

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log, Path);
	}
	Debug::Log << "Compiling Shader::Code " << ID << " done" << Debug::Done;
}

Shader::Code::ECompileLog::ECompileLog(const std::string log, const std::string path)
{
	Log = log;
	Path = path;
	Text = "Log returned from compiling File '" + Path + "'.\n\n" + Log;
}
const char * Shader::Code::ECompileLog::what() const throw()
{
	return Text.c_str();
}



bool str_ends_with(const std::string & str, const std::string & pattern)
{
	int len_s = str.length();
	int len_p = pattern.length();
	if (len_s < len_p) { return false; }
	
	int off_s = len_s - len_p;
	for (int i = 0; i < len_p; i++)
	{
		if (str[off_s + i] != pattern[i])
		{
			return false;
		}
	}
	return true;
}

Shader::Code Shader::Code::FromFile(const FileContext & file)
{
	std::string ext = file.Extension();

	GLenum type;
	if      (ext == ".glsg") { throw EInvalidFileExtention(file.Path.ToString()); }
	else if (ext == ".vert") { type = GL_VERTEX_SHADER; }
	else if (ext == ".geom") { type = GL_GEOMETRY_SHADER; }
	else if (ext == ".frag") { type = GL_FRAGMENT_SHADER; }
	else { throw EInvalidFileExtention(file.Path.ToString()); }

	return Shader::Code(type, file.LoadText(), file.Path.ToString());
}

Shader::Code::EInvalidFileExtention::EInvalidFileExtention(const std::string & path)
{
	Path = path;
	Text = "File '" + Path + "' has an invalid Extention.";
}
const char * Shader::Code::EInvalidFileExtention::what() const throw()
{
	return Text.c_str();
}
