
#include "Graphics/Uniform/Abstract3D/UniPoint3D.hpp"
#include "OpenGL/openGL.h"

UniPoint3D::UniPoint3D(std::string name, BaseShader & shader) :
	GenericUniformBase<Point3D>(name, shader)
{
	Location = shader.UniformFind(name);
	std::cout << "UniPoint3D.Location: " << Location << "\n";
	//shader.Uniforms.push_back(this);
}

void UniPoint3D::PutData(Point3D p)
{
	glUniform3fv(Location, 1, (float*)(&p));
}
