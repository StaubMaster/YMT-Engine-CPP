#include "Graphics/Uniform/Data/2D/UniPoint2D.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "DataStruct/Point2D.hpp"

#include "OpenGL/openGL.h"



UniPoint2D::UniPoint2D(std::string name, BaseShader & shader) :
	GenericUniformBase<Point2D>(name, shader)
{
	Location = shader.UniformFind(name);
}

void UniPoint2D::PutData(Point2D p)
{
	glUniform2fv(Location, 1, (float*)(&p));
}
