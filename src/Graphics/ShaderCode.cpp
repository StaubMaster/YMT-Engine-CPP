#include "Graphics/ShaderCode.hpp"
#include <iostream>



ShaderCode::ShaderCode(GLenum type, const std::string code, const std::string path)
{
	Path = path;
	ID = glCreateShader(type);
	std::cout << "++++ Shader " << ID << "\n";
	Compile(code);
}
ShaderCode::~ShaderCode()
{
	std::cout << "---- Shader " << ID << "\n";
	glDeleteShader(ID);
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
	std::cout << "Compiling Shader " << ID << " ...\n";
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
	std::cout << "Compiling Shader " << ID << " done\n";
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
	GLenum type;
	if (str_ends_with(file.FilePath, ".glsg")) { throw EInvalidFileExtention(file.FilePath); }
	else if (str_ends_with(file.FilePath, ".vert")) { type = GL_VERTEX_SHADER; }
	else if (str_ends_with(file.FilePath, ".geom")) { type = GL_GEOMETRY_SHADER; }
	else if (str_ends_with(file.FilePath, ".frag")) { type = GL_FRAGMENT_SHADER; }
	else { throw EInvalidFileExtention(file.FilePath); }
	return ShaderCode(type, file.LoadText(), file.FilePath);
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
