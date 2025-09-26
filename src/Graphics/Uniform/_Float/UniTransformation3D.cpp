
#include "Graphics/Uniform/Float/UniTransformation3D.hpp"

UniTransformation3D::UniTransformation3D(const BaseShader * program, const std::string & name)
 : UniFloat3(program, name, 3)
{
	
}
UniTransformation3D::~UniTransformation3D()
{
	
}



void UniTransformation3D::Value(const Transformation3D & trans)
{
	Set((const float *)&trans);
}
