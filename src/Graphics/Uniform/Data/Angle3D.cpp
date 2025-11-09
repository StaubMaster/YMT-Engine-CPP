#include "Graphics/Uniform/Data/Angle3D.hpp"
#include "Graphics/Shader/Base.hpp"
#include "DataStruct/Angle3D.hpp"
#include "OpenGL/openGL.h"



Uniform::Angle3D::Angle3D(std::string name, Shader::Base & shader) : GBase(name, shader)
{
	Location = shader.UniformFind(name);
}

void Uniform::Angle3D::PutData(::Angle3D a)
{
	glUniformMatrix3fv(Location, 1, true, (const float *)(&a.Mat));
}
