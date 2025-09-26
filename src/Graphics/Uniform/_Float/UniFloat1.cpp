#include "Graphics/Uniform/Float/UniFloat1.hpp"

UniFloat1::UniFloat1(const BaseShader * program, const std::string & name, int count)
	: UniFloatN(program, name, count, 1)
{
	
}
UniFloat1::~UniFloat1()
{

}



void UniFloat1::Set(const float * data)
{
	if (Program -> Is())
	{
		glUniform1fv(Location, Count, data);
		
	}
	else
	{
		StoreData(data);
	}
}
