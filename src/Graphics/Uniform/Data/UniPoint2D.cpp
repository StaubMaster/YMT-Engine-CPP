#include "Graphics/Uniform/Data/UniPoint2D.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::Point2D::Point2D(std::string name, BaseShader & shader) : GenericUniformBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::Point2D::PutData(::Point2D p)
{
	glUniform2fv(Location, 1, (float*)(&p));
}
