#pragma once
#include <iostream>

template <typename T>
class Point2D
{
public:
	//constructor
	Point2D(T X, T Y);
	//copy constructor
	Point2D(const Point2D<T>& copy);
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
	friend std::ostream& operator<<(std::ostream& os, Point2D<T>& p);

	T x;
	T y;
private:

};

template <typename T>
class Point3D : Point2D<T>
{
public:
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

	friend std::ostream& operator<<(std::ostream& os, Point3D<T>& p);

	T z;
private:

};

template <typename T>
class Point4D : Point3D<T>
{
public:
	//constructor
	Point4D(T X, T Y, T Z, T W);
	//copy constructor
	Point4D(const Point4D<T>& copy);
	//Point 2D constructor
	Point4D(const Point2D<T>& XY, T Z, T W);
	Point4D(const Point2D<T>& XY, const Point2D<T>& ZW);
	//Point 3D constructor
	Point4D(const Point3D<T>& XYZ, T W);
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

	friend std::ostream& operator<<(std::ostream& os, Point4D<T>& b);

	T w;
private:

};

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
std::ostream& operator<<(std::ostream& os, Point2D<T>& p)
{
	return os << "(" << p.x << ", " << p.y << ")";
}

template <typename T>
Point3D<T>::Point3D(T X, T Y, T Z) : x(X), y(Y), z(Z)
{
}

template <typename T>
Point3D<T>::Point3D(const Point2D<T>& XY, T Z) : x(XY.x), y(XY.y), z(Z)
{
}

template <typename T>
Point3D<T>::Point3D(const Point3D<T>& copy) : x(copy.x), y(copy.y), z(copy.z)
{
}

template <typename T>
Point3D<T>& Point3D<T>::operator=(const Point3D<T>& other)
{
	this->x = other.x;
	this->y = other.y;
	this->Z = other.z;

	return *this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator+(const Point2D<T>& rhs)
{
	return Point3D<T>(x + rhs.x, y + rhs.y, z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator+(const Point3D<T>& rhs)
{
	return Point3D<T>(x + rhs.x, y + rhs.y, z + rhs.z);
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
	return Point3D<T>(x - rhs.x, y - rhs.y, z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator-(const Point3D<T>& rhs)
{
	return Point3D<T>(x - rhs.x, y - rhs.y, z - rhs.z);
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
	return Point3D<T>(x * rhs.x, y * rhs.y, z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator*(const Point3D<T>& rhs)
{
	return Point3D<T>(x * rhs.x, y * rhs.y, z * rhs.z);
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
	reutrn* this;
}

template <typename T>
Point3D<T>& Point3D<T>::operator/(const Point2D<T>& rhs)
{
	return Point3D<T>(x / rhs.x, y / rhs.y, z);
}

template <typename T>
Point3D<T>& Point3D<T>::operator/(const Point3D<T>& rhs)
{
	return Point3D<T>(x / rhs.x, y / rhs.y, z / rhs.z);
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
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Point3D<T>& p)
{
	return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

template <typename T>
Point4D<T>::Point4D(T X, T Y, T Z, T W) : x(X), y(Y), z(Z), w(W)
{
}

template <typename T>
Point4D<T>::Point4D(const Point2D<T>& XY, T Z, T W) : x(XY.x), y(XY.y), z(Z), w(W)
{
}

template <typename T>
Point4D<T>::Point4D(const Point2D<T>& XY, const Point2D<T>& ZW) : x(XY.x), y(XY.y), z(ZW.z), w(ZW.w)
{
}

template <typename T>
Point4D<T>::Point4D(const Point3D<T>& XYZ, T W) : x(XYZ.x), y(XYZ.y), z(XYZ.z), w(W)
{
}

template <typename T>
Point4D<T>::Point4D(const Point4D<T>& copy) : x(copy.x), y(copy.y), z(copy.z), w(copy.w)
{
}

template <typename T>
Point4D<T>& Point4D<T>::operator=(const Point4D<T>& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;

	return *this;
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point2D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point3D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator+(const Point4D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
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
	return Point4D<T>(x - rhs.x, y - rhs.y, z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator-(const Point3D<T>& rhs)
{
	return Point4D<T>(x - rhs.x, y - rhs.y, z - rhs.z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator-(const Point4D<T>& rhs)
{
	return Point4D<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
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
	return Point4D<T>(x * rhs.x, y * rhs.y, z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator*(const Point3D<T>& rhs)
{
	return Point4D<T>(x * rhs.x, y * rhs.y, z * rhs.z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator*(const Point4D<T>& rhs)
{
	return Point4D<T>(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
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
	return Point4D<T>(x / rhs.x, y / rhs.y, z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator/(const Point3D<T>& rhs)
{
	return Point4D<T>(x / rhs.x, y / rhs.y, z / rhs.z, w);
}

template <typename T>
Point4D<T>& Point4D<T>::operator/(const Point4D<T>& rhs)
{
	return Point4D<T>(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
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
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Point4D<T>& p)
{
	return os << "(" << p.x << ", " << p.y << ", " << p.z << ", " << p.w << ")";
}