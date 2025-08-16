#include "../../include/Graphics/ShaderCode.hpp"
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
}
const char * ShaderCode::ECompileLog::what() const throw()
{
	std::string str = "";
	str += "Log returned from compiling File '" + Path + "'.\n\n" + Log;
	return str.c_str();
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
std::string FileReadAllText(const std::string & path)
{
	std::ifstream file;
	file.open(path.c_str());
	std::string text = "";
	
	if (file.fail())
	{
		std::cout << "Error\n";
		return "";
	}

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		text += line + "\n";
	}
	
	file.close();
	return (text);
}

ShaderCode * ShaderCode::FromFile(const std::string & path)
{
	GLenum type;
	if (str_ends_with(path, ".glsg")) { throw EInvalidFileExtention(path); }
	else if (str_ends_with(path, ".vert")) { type = GL_VERTEX_SHADER; }
	else if (str_ends_with(path, ".geom")) { type = GL_GEOMETRY_SHADER; }
	else if (str_ends_with(path, ".frag")) { type = GL_FRAGMENT_SHADER; }
	else { throw EInvalidFileExtention(path); }
	return new ShaderCode(type, FileReadAllText(path), path);
}

ShaderCode::EInvalidFileExtention::EInvalidFileExtention(const std::string & path)
{
	Path = path;
}
const char * ShaderCode::EInvalidFileExtention::what() const throw()
{
	std::string str = "";
	str += "File '" + Path + "' has an invalid Extention.";
	return str.c_str();
}
