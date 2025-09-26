
#include "Graphics/Uniform/Abstract3D/UniAngle3D.hpp"
#include "OpenGL/openGL.h"

UniAngle3D::UniAngle3D(std::string name, BaseShader & shader) :
	GenericShaderUniform<Angle3D>(name, shader)
{
	LocationSin = shader.UniformFind(name + ".Sin");
	LocationCos = shader.UniformFind(name + ".Cos");
	std::cout << "UniAngle3D.LocationSin: " << LocationSin << "\n";
	std::cout << "UniAngle3D.LocationCos: " << LocationCos << "\n";
	//shader.Uniforms.push_back(this);
}

void UniAngle3D::PutData(Angle3D a)
{
	glUniform3fv(LocationSin, 1, ((float*)(&a) + 0));
	glUniform3fv(LocationCos, 1, ((float*)(&a) + 3));
}
