#include "Graphics/Uniform/Data/3D/UniTrans3D.hpp"

#include "OpenGL/openGL.h"
#include <iostream>



UniTrans3D::UniTrans3D(std::string name, BaseShader & shader) :
	GenericUniformBase<Transformation3D>(name, shader),
	Pos(name + ".Pos", shader),
	Rot(name + ".Rot", shader)
{
	//shader.Uniforms.push_back(this);
}

void UniTrans3D::PutData(Transformation3D t)
{
	//std::cout << "t.Pos: " << t.Pos << "\n";
	//std::cout << "t.Rot: " << t.Rot << "\n";
	Pos.PutData(t.Pos);
	Rot.PutData(t.Rot);
}







MultiTrans3D::MultiTrans3D(std::string name) :
	GenericMultiformBase<UniTrans3D, Transformation3D>(name)
{

}
