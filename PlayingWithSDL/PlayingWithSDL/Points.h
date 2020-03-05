#pragma once
#include <iostream>

template <typename T>
class Point2D
{
public:
	//defualt constructor
	Point2D<T>();
	//constructor
	Point2D<T>(T X, T Y);
	//copy constructor
	Point2D<T>(const Point2D<T>& copy);
	//assignment operator
	Point2D<T>& operator=(const Point2D<T>& other);
	//addition
	Point2D<T>& operator+(const Point2D<T>& rhs);
	Point2D<T>& operator+=(const Point2D<T>& rhs);
	//subtraction
	Point2D<T>& operator-(const Point2D<T>& rhs);
	Point2D<T>& operator-=(const Point2D<T>& rhs);
	//multiplication
	Point2D<T>& operator*(const Point2D<T>& rhs);
	Point2D<T>& operator*=(const Point2D<T>& rhs);
	//Divison
	Point2D<T>& operator/(const Point2D<T>& rhs);
	Point2D<T>& operator/=(const Point2D<T>& rhs);

	//Comparison
	bool operator==(const Point2D<T>& rhs);

	//output
	friend std::ostream& operator<<(std::ostream& os, Point2D<T>& p)
	{
		return os << "(" << p.x << ", " << p.y << ")";
	}

	T x;
	T y;
private:

};

template <typename T>
class Point3D : public Point2D<T>
{
public:
	//Defualt constructor
	Point3D<T>();
	//constructor
	Point3D(T X, T Y, T Z);
	//copy constructor
	Point3D(const Point3D<T>& copy);
	//Point2D constrcutor
	Point3D(const Point2D<T>& p, T Z);
	//Assignment constructor
	Point3D<T>& operator=(const Point3D<T>& other);
	//Addition
	Point3D<T>& operator+(const Point3D<T>& rhs);
	Point3D<T>& operator+(const Point2D<T>& rhs);
	Point3D<T>& operator+=(const Point3D<T>& rhs);
	Point3D<T>& operator+=(const Point2D<T>& rhs);
	//Subtraction
	Point3D<T>& operator-(const Point3D<T>& rhs);
	Point3D<T>& operator-(const Point2D<T>& rhs);
	Point3D<T>& operator-=(const Point2D<T>& rhs);
	Point3D<T>& operator-=(const Point3D<T>& rhs);
	//Multiplication
	Point3D<T>& operator*(const Point2D<T>& rhs);
	Point3D<T>& operator*(const Point3D<T>& rhs);
	Point3D<T>& operator*=(const Point2D<T>& rhs);
	Point3D<T>& operator*=(const Point3D<T>& rhs);
	//Division
	Point3D<T>& operator/(const Point2D<T>& rhs);
	Point3D<T>& operator/(const Point3D<T>& rhs);
	Point3D<T>& operator/=(const Point2D<T>& rhs);
	Point3D<T>& operator/=(const Point3D<T>& rhs);

	//Comparison
	bool operator==(const Point3D<T>& rhs);

	friend std::ostream& operator<<(std::ostream& os, Point3D<T>& p)
	{
		return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
	}

	T z;
private:

};

template <typename T>
class Point4D : public Point3D<T>
{
public:
	//defualt constructor
	Point4D<T>();
	//constructor
	Point4D<T>(T X, T Y, T Z, T W);
	//copy constructor
	Point4D<T>(const Point4D<T>& copy);
	//Point 2D constructor
	Point4D<T>(const Point2D<T>& XY, T Z, T W);
	Point4D<T>(const Point2D<T>& XY, const Point2D<T>& ZW);
	//Point 3D constructor
	Point4D<T>(const Point3D<T>& XYZ, T W);
	//Assignment operator
	Point4D<T>& operator=(const Point4D<T>& other);
	//Addition
	Point4D<T>& operator+(const Point2D<T>& rhs);
	Point4D<T>& operator+(const Point3D<T>& rhs);
	Point4D<T>& operator+(const Point4D<T>& rhs);
	Point4D<T>& operator+=(const Point2D<T>& rhs);
	Point4D<T>& operator+=(const Point3D<T>& rhs);
	Point4D<T>& operator+=(const Point4D<T>& rhs);
	//Subtraction
	Point4D<T>& operator-(const Point2D<T>& rhs);
	Point4D<T>& operator-(const Point3D<T>& rhs);
	Point4D<T>& operator-(const Point4D<T>& rhs);
	Point4D<T>& operator-=(const Point2D<T>& rhs);
	Point4D<T>& operator-=(const Point3D<T>& rhs);
	Point4D<T>& operator-=(const Point4D<T>& rhs);
	//Mulitplication
	Point4D<T>& operator*(const Point2D<T>& rhs);
	Point4D<T>& operator*(const Point3D<T>& rhs);
	Point4D<T>& operator*(const Point4D<T>& rhs);
	Point4D<T>& operator*=(const Point2D<T>& rhs);
	Point4D<T>& operator*=(const Point3D<T>& rhs);
	Point4D<T>& operator*=(const Point4D<T>& rhs);
	//Division
	Point4D<T>& operator/(const Point2D<T>& rhs);
	Point4D<T>& operator/(const Point3D<T>& rhs);
	Point4D<T>& operator/(const Point4D<T>& rhs);
	Point4D<T>& operator/=(const Point2D<T>& rhs);
	Point4D<T>& operator/=(const Point3D<T>& rhs);
	Point4D<T>& operator/=(const Point4D<T>& rhs);

	//comparison
	bool operator==(const Point4D<T>& rhs);

	friend std::ostream& operator<<(std::ostream& os, Point4D<T>& p)
	{
		return os << "(" << p.x << ", " << p.y << ", " << p.z << ", " << p.w << ")";
	}

	T w;
private:

};

template <typename T>
Point2D<T>::Point2D()
{
	x = 0;
	y = 0;
}

template <typename T>
Point2D<T>::Point2D(T X, T Y) : x(X), y(Y)
{
}

template <typename T>
Point2D<T>::Point2D(const Point2D<T>& copy) : x(copy.x), y(copy.y)
{
}

template <typename T>
Point2D<T>& Point2D<T>::operator=(const Point2D<T>& rhs)
{
	x = rhs.x;
	y = rhs.y;

	return *this;
}

template <typename T>
Point2D<T>& Point2D<T>::operator+(const Point2D<T>& rhs)
{
	return Point2D<T>(x + rhs.x, y + rhs.y);
}

template <typename T>
Point2D<T>& Point2D<T>::operator+=(const Point2D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point2D<T>& Point2D<T>::operator-(const Point2D<T>& rhs)
{
	return Point2D<T>(x - rhs.x, y - rhs.y);
}

template <typename T>
Point2D<T>& Point2D<T>::operator-=(const Point2D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point2D<T>& Point2D<T>::operator*(const Point2D<T>& rhs)
{
	return Point2D<T>(x * rhs.x, y * rhs.y);
}

template <typename T>
Point2D<T>& Point2D<T>::operator*=(const Point2D<T>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template <typename T>
Point2D<T>& Point2D<T>::operator/(const Point2D<T>& rhs)
{
	return Point2D<T>(x / rhs.x, y / rhs.y);
}

template <typename T>
Point2D<T>& Point2D<T>::operator/=(const Point2D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
bool Point2D<T>::operator==(const Point2D<T>& rhs)
{
	return (x == rhs.x && y == rhs.y);
}

template <typename T>
Point3D<T>::Point3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template <typename T>
Point3D<T>::Point3D(T X, T Y, T Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
}

template <typename T>
Point3D<T>::Point3D(const Point2D<T>& XY, T Z)
{
	this->x = XY.x;
	this->y = XY.y;
	this->z = Z;
}

template <typename T>
Point3D<T>::Point3D(const Point3D<T>& copy)
{
	this->x = copy.x;
	this->y = copy.y;
	this->z = copy.z;
}

template <typename T>
Point3D<T>& Point3D<T>::operator=(const Point3D<T>& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;

	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator+(const Point2D<T>& rhs)
{
	return Point3D<T>(this->x + rhs.x, this->y + rhs.y, this->z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator+(const Point3D<T>& rhs)
{
	return Point3D<T>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator+=(const Point2D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator+=(const Point3D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator-(const Point2D<T>& rhs)
{
	return Point3D<T>(this->x - rhs.x, this->y - rhs.y, this->z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator-(const Point3D<T>& rhs)
{
	return Point3D<T>(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator-=(const Point2D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator-=(const Point3D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator*(const Point2D<T>& rhs)
{
	return Point3D<T>(this->x * rhs.x, this->y * rhs.y, this->z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator*(const Point3D<T>& rhs)
{
	return Point3D<T>(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator*=(const Point2D<T>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator*=(const Point3D<T>& rhs)
{
	*this = *this * rhs;
	return* this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator/(const Point2D<T>& rhs)
{
	return Point3D<T>(this->x / rhs.x, this->y / rhs.y, this->z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator/(const Point3D<T>& rhs)
{
	return Point3D<T>(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator/=(const Point2D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator/=(const Point3D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
bool Point3D<T>::operator==(const Point3D<T>& rhs)
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z);
}

template <typename T>
Point4D<T>::Point4D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

template <typename T>
Point4D<T>::Point4D(T X, T Y, T Z, T W)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	this->w = W;
}

template <typename T>
Point4D<T>::Point4D(const Point2D<T>& XY, T Z, T W)
{
	this->x = XY.x;
	this->y = XY.y;
	this->z = Z;
	this->w = W;
}

template <typename T>
Point4D<T>::Point4D(const Point2D<T>& XY, const Point2D<T>& ZW)
{
	this->x = XY.x;
	this->y = XY.y;
	this->z = ZW.x;
	this->w = ZW.y;
}

template <typename T>
Point4D<T>::Point4D(const Point3D<T>& XYZ, T W)
{
	this->x = XYZ.x;
	this->y = XYZ.y;
	this->z = XYZ.z;
	this->w = W;
}

template <typename T>
Point4D<T>::Point4D(const Point4D<T>& copy)
{
	this->x = copy.x;
	this->y = copy.y;
	this->z = copy.z;
	this->w = copy.w;
}

template <typename T>
Point4D<T>& Point4D<T>::operator=(const Point4D<T>& other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;

	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point2D<T>& rhs)
{
	return Point4D<T>(this->x + rhs.x, this->y + rhs.y, this->z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point3D<T>& rhs)
{
	return Point4D<T>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point4D<T>& rhs)
{
	return Point4D<T>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator+=(const Point2D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator+=(const Point3D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator+=(const Point4D<T>& rhs)
{
	*this = *this + rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator-(const Point2D<T>& rhs)
{
	return Point4D<T>(this->x - rhs.x, this->y - rhs.y, this->z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator-(const Point3D<T>& rhs)
{
	return Point4D<T>(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator-(const Point4D<T>& rhs)
{
	return Point4D<T>(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator-=(const Point2D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator-=(const Point3D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator-=(const Point4D<T>& rhs)
{
	*this = *this - rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator*(const Point2D<T>& rhs)
{
	return Point4D<T>(this->x * rhs.x, this->y * rhs.y, this->z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator*(const Point3D<T>& rhs)
{
	return Point4D<T>(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator*(const Point4D<T>& rhs)
{
	return Point4D<T>(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w * rhs.w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator*=(const Point2D<T>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator*=(const Point3D<T>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator*=(const Point4D<T>& rhs)
{
	*this = *this * rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator/(const Point2D<T>& rhs)
{
	return Point4D<T>(this->x / rhs.x, this->y / rhs.y, this->z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator/(const Point3D<T>& rhs)
{
	return Point4D<T>(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z, this->w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator/(const Point4D<T>& rhs)
{
	return Point4D<T>(this->x / rhs.x, this->y / rhs.y, this->z / rhs.z, this->w / rhs.w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator/=(const Point2D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator/=(const Point3D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator/=(const Point4D<T>& rhs)
{
	*this = *this / rhs;
	return *this;
}

template <typename T>
bool Point4D<T>::operator==(const Point4D<T>& rhs)
{
	return (this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->w == rhs.w);
}