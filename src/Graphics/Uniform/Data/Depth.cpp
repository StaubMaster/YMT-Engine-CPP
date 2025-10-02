#include "Graphics/Uniform/Data/Depth.hpp"
#include "DataStruct/Depth.hpp"
#include "OpenGL/openGL.h"
#include <iostream>



Uniform::Depth::Depth(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Factors(name + ".Factors", shader),
	Range(name + ".Range", shader),
	Color(name + ".Color", shader)
{
	
}

void Uniform::Depth::PutData(::Depth val)
{
	Factors.PutData(val.Factors);
	Range.PutData(val.Range);
	Color.PutData(val.Color);
}
