#include "Lerp.h"

float Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

bool isAbout(float a, float b)
{
	return (abs(a - b) <= FUZZYCHECK);
}