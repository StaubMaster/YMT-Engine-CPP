#include "Graphics/Uniform/Data/Point3D.hpp"
#include "DataStruct/Point3D.hpp"



Uniform::Point3D::Point3D(std::string name, Shader::Base & shader) : GBase(name, shader),
	Location(name, shader)
{ }



void Uniform::Point3D::PutData(::Point3D p)
{
	Location.PutVoid(&p);
}
