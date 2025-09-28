#include "Graphics/Uniform/Data/UniDepth.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



UniDepth::UniDepth(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Factors(name + ".Factors", shader),
	Range(name + ".Range", shader),
	Color(name + ".Color", shader)
{
	
}

void UniDepth::PutData(Depth val)
{
	Factors.PutData(val.Factors);
	Range.PutData(val.Range);
	Color.PutData(val.Color);
}







MultiDepth::MultiDepth(std::string name) : GenericMultiformBase(name)
{

}
