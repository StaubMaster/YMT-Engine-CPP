#include "TimeMeasure.hpp"
#include "OpenGL/openGL.h"



TimeMeasure::TimeMeasure()
{
	Count = 0;
	Index = 0;
	Memory = new double[Limit];
}
TimeMeasure::~TimeMeasure()
{
	delete [] Memory;
}



void TimeMeasure::T0()
{
	TimeStamp = glfwGetTime();
}
void TimeMeasure::T1()
{
	Memory[Index] = glfwGetTime() - TimeStamp;
	if (Index < Limit - 1) { Index++; } else { Index = 0; }
	if (Count < Limit - 1) { Count++; }
}
double TimeMeasure::Average()
{
	double sum = 0;
	for (int i = 0; i < Count; i++)
	{
		sum += Memory[i];
	}
	return sum / Count;
}
