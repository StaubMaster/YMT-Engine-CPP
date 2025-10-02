#include "Graphics/Uniform/Data/UniAngle3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/Angle3D.hpp"
#include "OpenGL/openGL.h"



Uniform::Angle3D::Angle3D(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	LocationSin = shader.UniformFind(name + ".Sin");
	LocationCos = shader.UniformFind(name + ".Cos");
}

void Uniform::Angle3D::PutData(::Angle3D a)
{
	glUniform3fv(LocationSin, 1, ((float*)(&a) + 0));
	glUniform3fv(LocationCos, 1, ((float*)(&a) + 3));
}
