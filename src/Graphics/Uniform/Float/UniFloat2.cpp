#include "Graphics/Uniform/Float/UniFloat2.hpp"

UniFloat2::UniFloat2(const BaseShader * program, const std::string & name, int count)
	: UniFloatN(program, name, count, 2)
{
	
}
UniFloat2::~UniFloat2()
{

}



void UniFloat2::Set(const float * data)
{
	if (Program -> Is())
	{
		glUniform2fv(Location, Count, data);
	}
	else
	{
		StoreData(data);
	}
}
