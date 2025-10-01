#include "Graphics/Uniform/Data/3D/UniAngle3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "DataStruct/Angle3D.hpp"

#include "OpenGL/openGL.h"



UniAngle3D::UniAngle3D(std::string name, BaseShader & shader) :
	GenericUniformBase<Angle3D>(name, shader)
{
	LocationSin = shader.UniformFind(name + ".Sin");
	LocationCos = shader.UniformFind(name + ".Cos");
}

void UniAngle3D::PutData(Angle3D a)
{
	glUniform3fv(LocationSin, 1, ((float*)(&a) + 0));
	glUniform3fv(LocationCos, 1, ((float*)(&a) + 3));
}
