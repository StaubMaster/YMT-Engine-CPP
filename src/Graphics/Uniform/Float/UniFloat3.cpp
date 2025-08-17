#include "Graphics/Uniform/Float/UniFloat3.hpp"

UniFloat3::UniFloat3(const BaseShader * program, const std::string & name, int count)
	: UniFloatN(program, name, count, 3)
{
	
}
UniFloat3::~UniFloat3()
{

}



void UniFloat3::Set(const float * data)
{
	//if (Program -> Is())
	if (true)
	{
		glUniform3fv(Location, Count, data);
	}
	else
	{
		UpdateData = data;
	}
}
