#include "Graphics/Uniform/Data/SizeRatio2D.hpp"
#include "Graphics/Shader/BaseShader.hpp"
#include "DataStruct/SizeRatio2D.hpp"
#include "DataStruct/Point2D.hpp"
#include "OpenGL/openGL.h"



Uniform::SizeRatio2D::SizeRatio2D(std::string name, BaseShader & shader) : GenericUniformBase(name, shader),
	Size(name + ".Size", shader),
	Ratio(name + ".Ratio", shader)
{

}

void Uniform::SizeRatio2D::PutData(::SizeRatio2D sr)
{
	Size.PutData(::Point2D(sr.W, sr.H));
	Ratio.PutData(::Point2D(sr.RatioW, sr.RatioH));
}
