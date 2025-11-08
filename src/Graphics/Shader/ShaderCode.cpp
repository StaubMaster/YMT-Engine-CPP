#include "Graphics/Shader/ShaderCode.hpp"
#include "FileContext.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>



ShaderCode::ShaderCode(GLenum type, const std::string code, const std::string path)
{
	Path = path;
	ID = glCreateShader(type);
	Debug::Log << "++++ ShaderCode " << ID << Debug::Done;
	Compile(code);
}
ShaderCode::~ShaderCode()
{
	Debug::Log << "---- ShaderCode " << ID << Debug::Done;
	glDeleteShader(ID);
}



int ShaderCode::getID() const
{
	return ID;
}

void ShaderCode::Attach(int ProgramID) const
{
	glAttachShader(ProgramID, ID);
}
void ShaderCode::Detach(int ProgramID) const
{
	glAttachShader(ProgramID, ID);
}

void ShaderCode::Compile(const std::string code)
{
	Debug::Log << "Compiling ShaderCode " << ID << " ..." << Debug::Done;
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
	Debug::Log << "Compiling ShaderCode " << ID << " done" << Debug::Done;
}

ShaderCode::ECompileLog::ECompileLog(const std::string log, const std::string path)
{
	Log = log;
	Path = path;
	Text = "Log returned from compiling File '" + Path + "'.\n\n" + Log;
}
const char * ShaderCode::ECompileLog::what() const throw()
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

ShaderCode ShaderCode::FromFile(const FileContext & file)
{
	std::string ext = file.Extension();

	GLenum type;
	if      (ext == ".glsg") { throw EInvalidFileExtention(file.Path.ToString()); }
	else if (ext == ".vert") { type = GL_VERTEX_SHADER; }
	else if (ext == ".geom") { type = GL_GEOMETRY_SHADER; }
	else if (ext == ".frag") { type = GL_FRAGMENT_SHADER; }
	else { throw EInvalidFileExtention(file.Path.ToString()); }

	return ShaderCode(type, file.LoadText(), file.Path.ToString());
}

ShaderCode::EInvalidFileExtention::EInvalidFileExtention(const std::string & path)
{
	Path = path;
	Text = "File '" + Path + "' has an invalid Extention.";
}
const char * ShaderCode::EInvalidFileExtention::what() const throw()
{
	return Text.c_str();
}
