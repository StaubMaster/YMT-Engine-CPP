#include "Graphics/Uniform/Data/3D/UniTrans3D.hpp"
#include "Graphics/Shader/BaseShader.hpp"

#include "DataStruct/Trans3D.hpp"

#include "OpenGL/openGL.h"



UniTrans3D::UniTrans3D(std::string name, BaseShader & shader) :
	GenericUniformBase<Trans3D>(name, shader),
	Pos(name + ".Pos", shader),
	Rot(name + ".Rot", shader)
{
	//shader.Uniforms.push_back(this);
}

void UniTrans3D::PutData(Trans3D t)
{
	//std::cout << "t.Pos: " << t.Pos << "\n";
	//std::cout << "t.Rot: " << t.Rot << "\n";
	Pos.PutData(t.Pos);
	Rot.PutData(t.Rot);
}







MultiTrans3D::MultiTrans3D(std::string name) :
	GenericMultiformBase<UniTrans3D, Trans3D>(name)
{

}
