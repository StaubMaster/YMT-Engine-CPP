#include "Data/1D/Range.hpp"



Range::Range()
{
	Min = 0;
	Len = 0;
	Max = 0;
}
Range::Range(float min, float max)
{
	Min = min;
	Len = max - min;
	Max = max;
}



void Range::ChangeMin(float min)
{
	Min = min;
	Len = Max - min;

}
void Range::ChangeMax(float max)
{
	Len = max - Min;
	Max = max;
}
