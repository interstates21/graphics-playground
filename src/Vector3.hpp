#ifndef V2_HPP
#define V2_HPP

#include "PixelBuff.hpp"
#include "main.hpp"


template <class T>
class Vector3
{

public:
    T x;
    T y;
    T z;
    
Vector3() : x(0), y(0), z(0) {}

Vector3(T a, T b, T c) : x(a), y(b), z(c) {}

Vector3<T> &operator++()
{

    x += 1;
    y += 1;
    z += 1;
    return (*this);
}


Vector3<T> &operator++(int)
{

    Vector3<T> tmp(*this);

    ++(*this);

    return tmp;
}


Vector3<T> operator-() const
{
    return (Vector3(-x, -y, -z));
}


Vector3<T> operator+(const Vector3 <T> &other) const
{
    return (Vector3(other.x + x, other.y + y, other.z + z));
}


Vector3<T> operator-(const Vector3 <T>&other) const
{
    return (Vector3(other.x - x, other.y - y, other.z - z));
}


Vector3<T> operator*(T scalar) const
{
    return (Vector3(x * scalar, y * scalar, z * scalar));
}



T operator*(const Vector3 <T>&rhs) const
{
    return (Vector3((x * rhs.x) + (y * rhs.y) + (z * rhs.z)));
}


Vector3 <T>cross(const Vector3 <T>&rhs) const
{
    Vector3 v;

    v.x = y * rhs.z - z * rhs.y;
    v.y = z * rhs.x - x * rhs.z;
    v.z = x * rhs.y - y * rhs.x;

    return (v);
}


operator bool() const
{
    return (x != 0 && y != 0 && z != 0);
}


void render(PixelBuff &p, Uint32 color) const{
    p.putPix(x, y, color);
}


    friend std::ostream& operator<<(std::ostream& out, const Vector3<T>& v);
    friend std::istream& operator<<(std::istream& in, const Vector3<T>& v);

};


template<typename T>
 std::istream &operator>>(std::istream &is, Vector3 <T> &p)
{
    is >>  p.x >> p.y >> p.z;

    return is;
}


template<typename T>
 std::ostream &operator<<(std::ostream &os, Vector3 <T> &p)
{
    os << "Vector3 -- x: " << p.x << ", y: " << p.y << << ", z: " << p.z << std::endl;

    return os;
}
#endif