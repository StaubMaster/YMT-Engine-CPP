
#include "Abstract2D/SizeRatio2D.hpp"

SizeRatio2D::SizeRatio2D()
{

}
SizeRatio2D::SizeRatio2D(float w, float h)
{
	W = w;
	H = h;
	Calc();
}



void SizeRatio2D::Calc()
{
	if (W == H)
	{
		RatioW = 1.0f;
		RatioH = 1.0f;
	}
	else if (W > H)
	{
		RatioW = H / W;
		RatioH = 1.0f;
	}
	else if (W < H)
	{
		RatioW = 1.0f;
		RatioH = W / H;
	}
}
