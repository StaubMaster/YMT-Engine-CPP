
#include "Graphics/Uniform/Abstract2D/UniSizeRatio2D.hpp"
#include "OpenGL/openGL.h"
#include <iostream>

UniSizeRatio2D::UniSizeRatio2D(std::string name, BaseShader & shader) :
	GenericUniformBase<SizeRatio2D>(name, shader),
	Size(name + ".Size", shader),
	Ratio(name + ".Ratio", shader)
{
	
}

void UniSizeRatio2D::PutData(SizeRatio2D sr)
{
	Size.PutData(Point2D(sr.W, sr.H));
	Ratio.PutData(Point2D(sr.RatioW, sr.RatioH));
}







MultiSizeRatio2D::MultiSizeRatio2D(std::string name) :
	GenericMultiformBase<UniSizeRatio2D, SizeRatio2D>(name)
{
	
}
