#include "Graphics/Uniform/UniBase.hpp"

UniBase::UniBase(const BaseShader * program, const std::string & name)
{
	Program = program;
	Location = program -> UniformFind(name);
}
UniBase::~UniBase()
{

}
