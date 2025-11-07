#include "Graphics/Uniform/Data/LInter.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/LInter.hpp"
#include "OpenGL/openGL.h"

#include <iostream>



Uniform::LInter::LInter(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	T0(name + ".T0", shader),
	T1(name + ".T1", shader)
{ }

void Uniform::LInter::PutData(::LInter val)
{
	T0.PutData(((const float *)&val) + 0);
	T1.PutData(((const float *)&val) + 1);
}
