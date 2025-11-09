#include "Graphics/Uniform/Trans3D.hpp"
#include "DataStruct/Trans3D.hpp"
#include "OpenGL/openGL.h"



Uniform::Trans3D::Trans3D(std::string name, Shader::Base & shader) : GBase(name, shader),
	Pos(name + ".Pos", shader),
	Rot(name + ".Rot", shader)
{ }

void Uniform::Trans3D::PutData(::Trans3D t)
{
	Pos.PutData(t.Pos);
	Rot.PutData(t.Rot);
}
