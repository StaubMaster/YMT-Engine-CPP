#include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "DataStruct/Point3D.hpp"

#include "OpenGL/openGL.h"



Uniform::Point3D::Point3D(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::Point3D::PutData(::Point3D p)
{
	glUniform3fv(Location, 1, (float*)(&p));
}
