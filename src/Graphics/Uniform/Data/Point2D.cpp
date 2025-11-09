#include "Graphics/Uniform/Data/Point2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::Point2D::Point2D(std::string name, Shader::Base & shader) : GBase(name, shader),
	Location(name, shader)
{ }

void Uniform::Point2D::PutData(::Point2D p)
{
	Location.PutVoid(&p);
}
