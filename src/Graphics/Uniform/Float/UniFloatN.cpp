#include "Graphics/Uniform/Float/UniFloatN.hpp"

UniFloatN::UniFloatN(const BaseShader * program, const std::string & name, int count, int len)
	: UniBase(program, name)
{
	Count = count;
	Size = count * len;
	UpdateData = NULL;
}
UniFloatN::~UniFloatN()
{
	
}



void UniFloatN::Update()
{
	if (UpdateData != NULL)
	{
		const float * data = UpdateData;
		UpdateData = NULL;
		Set(data);
	}
}
