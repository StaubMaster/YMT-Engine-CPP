#include "Graphics/Uniform/SizeRatio2D.hpp"
#include "DataStruct/SizeRatio2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::SizeRatio2D::SizeRatio2D(std::string name, Shader::Base & shader) : GBase(name, shader),
	Size(name + ".Size", shader),
	Ratio(name + ".Ratio", shader)
{

}

void Uniform::SizeRatio2D::PutData(::SizeRatio2D sr)
{
	Size.PutData(::Point2D(sr.W, sr.H));
	Ratio.PutData(::Point2D(sr.RatioW, sr.RatioH));
}
