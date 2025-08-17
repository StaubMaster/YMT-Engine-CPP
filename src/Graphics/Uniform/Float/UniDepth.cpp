#include "Graphics/Uniform/Float/UniDepth.hpp"

UniDepth::UniDepth(const BaseShader * program, const std::string & name)
	: UniFloat1(program, name, 7)
{

}
UniDepth::~UniDepth()
{

}



void UniDepth::Value(float near, float far)
{
	float data[7];

	data[0] = near;
	data[1] = far;

	data[2] = data[1] - data[0];
	data[3] = data[1] + data[0];
	data[4] = data[1] * data[0] * 2;

	data[5] = data[3] / data[2];
	data[6] = data[4] / data[2];

	Set(data);
}
