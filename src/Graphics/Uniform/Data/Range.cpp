#include "Graphics/Uniform/Data/Range.hpp"
#include "DataStruct/Range.hpp"
#include "OpenGL/openGL.h"



Uniform::Range::Range(std::string name, Shader::Base & shader) : GBase(name, shader),
	Min(name + ".Min", shader),
	Len(name + ".Len", shader),
	Max(name + ".Max", shader)
{ }

void Uniform::Range::PutData(::Range val)
{
	Min.PutVoid(&val.Min);
	Len.PutVoid(&val.Len);
	Max.PutVoid(&val.Max);
}
