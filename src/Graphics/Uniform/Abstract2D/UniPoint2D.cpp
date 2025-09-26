
#include "Graphics/Uniform/Abstract2D/UniPoint2D.hpp"
#include "OpenGL/openGL.h"
#include <iostream>

UniPoint2D::UniPoint2D(std::string name, BaseShader & shader) :
	GenericShaderUniform<Point2D>(name, shader)
{
	Location = shader.UniformFind(name);
}

void UniPoint2D::PutData(Point2D p)
{
	glUniform2fv(Location, 1, (float*)(&p));
}
