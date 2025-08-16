#include "../../include/Graphics/BaseShader.hpp"



BaseShader::BaseShader(const ShaderCode ** code, int count)
{
	ID = glCreateProgram();
	std::cout << "++++ BaseShader " << ID << "\n";
	Compile(code, count);
}
BaseShader::~BaseShader()
{
	std::cout << "---- BaseShader " << ID << "\n";
	glDeleteProgram(ID);
}



void BaseShader::Use()
{
	glUseProgram(ID);
}
bool BaseShader::Is()
{
	return false;
}



int BaseShader::UniformFind(const std::string & name)
{
	int location = glGetUniformLocation(ID, name.c_str());
	if (location == -1)
	{
		std::cout << "Uni '" << name <<"' not found in Prog " << ID << ".\n";
	}
	else
	{
		std::cout << "Uni '" << name << "' found at " << location << " in Prog " << ID << ".\n";
	}
	return location;
}



void BaseShader::Compile(const ShaderCode ** code, int count)
{
	std::cout << "Compiling BaseShader " << ID << " ...\n";
	for (int i = 0; i < count; i++) { code[i] -> Attach(ID); }
	glLinkProgram(ID);
	for (int i = 0; i < count; i++) { code[i] -> Detach(ID); }

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log);
	}
	std::cout << "Compiling BaseShader " << ID << " done\n";
}

BaseShader::ECompileLog::ECompileLog(const std::string log)
{
	Log = log;
}
const char * BaseShader::ECompileLog::what() const throw()
{
	std::string str = "";
	str += "Log returned from compiling File.\n\n" + Log;
	return str.c_str();
}
