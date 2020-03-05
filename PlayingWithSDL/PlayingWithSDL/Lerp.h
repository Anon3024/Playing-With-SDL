#pragma once
#include "Points.h"
#include <math.h>
//Constant "near" Value
#define FUZZYCHECK 0.1
//This file contains Lerp and Easing Functions. Fun stuff.

/*********************************************************
* Lerp. Linear Interpleration.
* Takes start value (a), end value (b), and precent value (t)
* returns a value that is t% of the way from a to b
*********************************************************/
float Lerp(float a, float b, float t);

template <typename T>
Point2D<T> Lerp(Point2D<T> a, Point2D<T> b, float t)
{
	Point2D<T> retVal = Point2D<T>(0, 0);

	retVal.x = a.x + (b.x - a.x) * t;
	retVal.y = a.y + (b.y - a.y) * t;

	return retVal;
}

template <typename T>
Point3D<T> Lerp(Point3D<T> a, Point3D<T> b, float t)
{
	Point3D<T> retVal = Point3D<T>(0, 0, 0);

	retVal.x = a.x + (b.x - a.x) * t;
	retVal.y = a.y + (b.y - a.y) * t;
	retVal.z = a.z + (b.z - a.z) * t;

	return retVal;
}

template <typename T>
Point4D<T> Lerp(Point4D<T> a, Point4D<T> b, float t)
{
	Point4D<T> retVal = Point4D<T>(0, 0, 0, 0);

	retVal.x = a.x + (b.x - a.x) * t;
	retVal.y = a.y + (b.y - a.y) * t;
	retVal.z = a.z + (b.z - a.z) * t;

	return retVal;
}

//is a about b?
bool isAbout(float a, float b);

template <typename T>
bool isAbout(Point2D<T> a, Point2D<T> b)
{
	return (abs(a.x - b.x) <= FUZZYCHECK && abs(a.y - b.y) <= FUZZYCHECK);
}

template <typename T>
bool isAbout(Point3D<T> a, Point3D<T> b)
{
	return (abs(a.x - b.x) <= FUZZYCHECK && abs(a.y - b.y) <= FUZZYCHECK && abs(a.z - b.z) <= FUZZYCHECK);
}

template <typename T>
bool isAbout(Point4D<T> a, Point4D<T> b)
{
	return (abs(a.x - b.x) <= FUZZYCHECK && abs(a.y - b.y <= FUZZYCHECK) && abs(a.z - b.z) <= FUZZYCHECK && abs(a.w - b.w) <= FUZZYCHECK);
}