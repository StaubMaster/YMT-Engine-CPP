#include "Graphics/Uniform/LInter.hpp"
#include "DataStruct/LInter.hpp"



Uniform::LInter::LInter(std::string name, Shader::Base & shader) : GBase(name, shader),
	T0(name + ".T0", shader),
	T1(name + ".T1", shader)
{ }

void Uniform::LInter::PutData(::LInter val)
{
	T0.PutData(((const float *)&val) + 0);
	T1.PutData(((const float *)&val) + 1);
}
