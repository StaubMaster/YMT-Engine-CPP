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
	if (UpdateData != NULL)
	{
		delete [] UpdateData;
	}
}



void UniFloatN::Update()
{
	if (UpdateData != NULL)
	{
		if (Program -> Is())
		{
			Set(UpdateData);
			delete [] UpdateData;
			UpdateData = NULL;
		}
	}
}
void UniFloatN::StoreData(const float * data)
{
	if (UpdateData != NULL)
	{
		delete [] UpdateData;
	}

	UpdateData = new float[Size];
	for (int i = 0; i < Size; i++)
	{
		UpdateData[i] = data[i];
	}
}
