#include "Graphics/Uniform/Data/3D/UniPoint3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "Data/3D/Point3D.hpp"

#include "OpenGL/openGL.h"



UniPoint3D::UniPoint3D(std::string name, BaseShader & shader) :
	GenericUniformBase<Point3D>(name, shader)
{
	Location = shader.UniformFind(name);
}

void UniPoint3D::PutData(Point3D p)
{
	glUniform3fv(Location, 1, (float*)(&p));
}
