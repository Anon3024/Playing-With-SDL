#pragma once

template <typename T>
class Point2D
{
public:
	//constructor
	Point2D(T X, T Y);
	//copy constructor
	Point2D(const Point2D<T>& copy);
	//assignment operator
	Point2D& operator=(const Point2D<T>& other);
	//addition
	Point2D& operator+(const Point2D<T>& rhs);
	Point2D& operator+=(const Point2D<T>& rhs);
	//subtraction
	Point2D& operator-(const Point2D<T>& rhs);
	Point2D& operator-=(const Point2D<T>& rhs);

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
	Point3D& operator=(const Point3D<T>& other);
	//Addition
	Point3D& operator+(const Point3D<T>& rhs);
	Point3D& operator+(const Point2D<T>& rhs);
	Point3D& operator+=(const Point3D<T>& rhs);
	Point3D& operator+=(const Point2D<T>& rhs);
	//Subtraction
	Point3D& operator-(const Point3D<T>& rhs);
	Point3D& operator-(const Point2D<T>& rhs);
	Point3D& operator-=(const Point2D<T>& rhs);
	Point3D& operator-=(const Point3D<T>& rhs);

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
	Point4D& operator=(const Point4D other);
	//Addition
	Point4D& operator+(const Point2D<T>& rhs);
	Point4D& operator+(const Point3D<T>& rhs);
	Point4D& operator+(const Point4D<T>& rhs);

	Point4D& operator+=(const Point2D<T>& rhs);
	Point4D& operator+=(const Point3D<T>& rhs);
	Point4D& operator+=(const Point4D<T>& rhs);
	//Subtraction
	Point4D& operator-(const Point2D<T>& rhs);
	Point4D& operator-(const Point3D<T>& rhs);
	Point4D& operator-(const Point4D<T>& rhs);

	Point4D& operator-=(const Point2D<T>& rhs);
	Point4D& operator-=(const Point3D<T>& rhs);
	Point4D& operator-=(const Point4D<T>& rhs);

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
Point4D<T>& Point4D<T>::operator+(const Point2D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z, w);
}

template<typename T>
Point4D<T>& Point4D<T>::operator+(const Point3D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z + rhs.z, w);
}

template<typename T>
Point4D<T>& Point4D<T>::operator+(const Point4D<T>& rhs)
{
	return Point4D<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}