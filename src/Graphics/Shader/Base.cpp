#include "Graphics/Shader/Base.hpp"
#include "Graphics/Shader/Code.hpp"
#include "Graphics/Uniform/Base/Base.hpp"

#include "Debug.hpp"
#include <sstream>

#include "OpenGL/openGL.h"
#include <iostream>

int Shader::Base::CurrentID = -1;



Shader::Base::Base(const Code * code, int count)
{
	ID = glCreateProgram();
	Debug::Log << "++++ BaseShader " << ID << Debug::Done;
	Compile(code, count);
}
Shader::Base::~Base()
{
	Debug::Log << "---- BaseShader " << ID << Debug::Done;
	glDeleteProgram(ID);
}



void Shader::Base::Use()
{
	if (!Is())
	{
		glUseProgram(ID);
		Shader::Base::CurrentID = ID;
		UniformsUpdate();
	}
}
bool Shader::Base::Is() const
{
	return (Shader::Base::CurrentID == ID);
}



void Shader::Base::UniformsUpdate()
{
	for (int i = 0; i < (int)Uniforms.size(); i++)
	{
		if (Uniforms[i] -> Changed)
		{
			Uniforms[i] -> PutData();
		}
	}
}
int Shader::Base::UniformFind(const std::string & name) const
{
	int location = glGetUniformLocation(ID, name.c_str());
	//std::cout << "Uniform '" << name <<"' " << location << " " << ID << ".\n";
	if (location == -1)
	{
		Debug::Log << "Shader " << ID << " Uniform " << name << " not found." << Debug::Done;
		//std::cout << "Uniform '" << name <<"' not found in Prog " << ID << ".\n";
	}
	else
	{
		Debug::Log << "Shader " << ID << " Uniform " << name << " found at " << location << "." << Debug::Done;
		//std::cout << "Uniform '" << name << "' found at " << location << " in Prog " << ID << ".\n";
	}
	return location;
}



void Shader::Base::Compile(const Code * code, int count)
{
	Debug::Log << "Compiling BaseShader " << ID << " ..." << Debug::Done;
	Debug::Log << "BaseShader " << ID << " using Code";
	for (int i = 0; i < count; i++) { Debug::Log << " " << code[i].getID(); }
	Debug::Log << Debug::Done;

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
	Debug::Log << "Compiling BaseShader " << ID << " done" << Debug::Done;
}

Shader::Base::ECompileLog::ECompileLog(const std::string log)
{
	Log = log;
	Text = "Log returned from compiling File.\n\n" + Log;
}
const char * Shader::Base::ECompileLog::what() const throw()
{
	return Text.c_str();
}
