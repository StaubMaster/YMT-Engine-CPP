#include "DataStruct/LInter.hpp"



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



void LInter::SetT0(float val) { _T0 = val; _T1 = 1.0 - val; }
void LInter::SetT1(float val) { _T1 = val; _T0 = 1.0 - val; }

float LInter::GetT0() { return _T0; }
float LInter::GetT1() { return _T1; }
