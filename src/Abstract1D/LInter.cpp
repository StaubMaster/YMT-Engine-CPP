#include "Abstract1D/LInter.hpp"



LInter::LInter()
{
	_T0 = 0.0f;
	_T1 = 0.0f;
}
LInter::LInter(float t0, float t1)
{
	_T0 = t0;
	_T1 = t1;
}



LInter LInter::T0()
{
	return LInter(1.0f, 0.0f);
}
LInter LInter::T1()
{
	return LInter(0.0f, 1.0f);
}



float LInter::Calc(float val0, float val1)
{
	return (val0 * _T0) + (val1 * _T1);
}
