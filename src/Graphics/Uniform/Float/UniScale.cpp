#include "Graphics/Uniform/Float/UniScale.hpp"

UniScale::UniScale(const BaseShader * program, const std::string & name)
	: UniFloat2(program, name, 2)
{

}
UniScale::~UniScale()
{

}



void UniScale::Value(float w, float h)
{
	float data[4];

	data[0] = w;
	data[1] = h;

	if (w == h)
	{
		data[2] = 1.0f;
		data[3] = 1.0f;
	}
	else if (w > h)
	{
		data[2] = h / w;
		data[3] = 1.0f;
	}
	else if (w < h)
	{
		data[2] = 1.0f;
		data[3] = w / h;
	}

	Set(data);
}
