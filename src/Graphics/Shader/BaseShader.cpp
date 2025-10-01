#include "Graphics/Shader/BaseShader.hpp"
#include "Graphics/Shader/ShaderCode.hpp"
#include "Graphics/Uniform/Base/UniformBase.hpp"

#include "OpenGL/openGL.h"
//#include <iostream>

int BaseShader::CurrentID = -1;



BaseShader::BaseShader(const ShaderCode * code, int count)
{
	ID = glCreateProgram();
	//std::cout << "++++ BaseShader " << ID << "\n";
	Compile(code, count);
}
BaseShader::~BaseShader()
{
	//std::cout << "---- BaseShader " << ID << "\n";
	glDeleteProgram(ID);
}



void BaseShader::Use()
{
	if (!Is())
	{
		glUseProgram(ID);
		BaseShader::CurrentID = ID;
		UniformsUpdate();
	}
}
bool BaseShader::Is() const
{
	return (BaseShader::CurrentID == ID);
}



void BaseShader::UniformsUpdate()
{
	for (int i = 0; i < (int)Uniforms.size(); i++)
	{
		if (Uniforms[i] -> Changed)
		{
			Uniforms[i] -> PutData();
		}
	}
}
int BaseShader::UniformFind(const std::string & name) const
{
	int location = glGetUniformLocation(ID, name.c_str());
	/*if (location == -1)
	{
		std::cout << "Uni '" << name <<"' not found in Prog " << ID << ".\n";
	}
	else
	{
		std::cout << "Uni '" << name << "' found at " << location << " in Prog " << ID << ".\n";
	}*/
	return location;
}



void BaseShader::Compile(const ShaderCode * code, int count)
{
	//std::cout << "Compiling BaseShader " << ID << " ...\n";
	for (int i = 0; i < count; i++) { code[i].Attach(ID); }
	glLinkProgram(ID);
	for (int i = 0; i < count; i++) { code[i].Detach(ID); }

	char log_arr[1024];
	int log_len = 0;
	glGetShaderInfoLog(ID, 1024, &log_len, log_arr);
	if (log_len != 0)
	{
		std::string log = std::string(log_arr, log_len);
		throw ECompileLog(log);
	}
	//std::cout << "Compiling BaseShader " << ID << " done\n";
}

BaseShader::ECompileLog::ECompileLog(const std::string log)
{
	Log = log;
	Text = "Log returned from compiling File.\n\n" + Log;
}
const char * BaseShader::ECompileLog::what() const throw()
{
	return Text.c_str();
}
