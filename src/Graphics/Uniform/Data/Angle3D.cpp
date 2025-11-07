#include "Graphics/Uniform/Data/Angle3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/Angle3D.hpp"
#include "OpenGL/openGL.h"

#include <iostream>



Uniform::Angle3D::Angle3D(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::Angle3D::PutData(::Angle3D a)
{
	glUniformMatrix3fv(Location, 1, true, (const float *)(&a.Mat));
}
