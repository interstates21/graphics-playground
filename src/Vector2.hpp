#ifndef V2_HPP
#define V2_HPP

#include "PixelBuff.hpp"
#include "main.hpp"


template <class T>
class Vector2
{

public:
    T x;
    T y;
    
Vector2() : x(0), y(0) {}

Vector2(T a, T b) : x(a), y(b) {}

Vector2<T> &operator++()
{

    x += 1;
    y += 1;
    return (*this);
}


Vector2<T> &operator++(int)
{

    Vector2<T> tmp(*this);

    ++(*this);

    return tmp;
}


Vector2<T> operator-() const
{
    return (Vector2(-x, -y));
}


Vector2<T> operator+(const Vector2 <T> &other) const
{
    return (Vector2(other.x + x, other.y + y));
}


Vector2<T> operator-(const Vector2 <T>&other) const
{
    return (Vector2(other.x - x, other.y - y));
}


Vector2<T> operator*(T scalar) const
{
    return (Vector2(x * scalar, y * scalar));
}



T operator*(const Vector2 <T>&rhs) const
{
    return (Vector2((x * rhs.x) + (y * rhs.y)));
}


Vector2 <T>cross(const Vector2 <T>&rhs) const
{
    Vector2 v;

    v.x = ;
    v.y = y * rhs.x;

    return (v);
}


operator bool() const
{
    return (x != 0 && y != 0);
}


void render(PixelBuff &p, Uint32 color) const{
    p.putPix(x, y, color);
}


    friend std::ostream& operator<<(std::ostream& out, const Vector2<T>& v);
    friend std::istream& operator<<(std::istream& in, const Vector2<T>& v);

};


template<typename T>
 std::istream &operator>>(std::istream &is, Vector2 <T> &p)
{
    is >>  p.x >> p.y;

    return is;
}


template<typename T>
 std::ostream &operator<<(std::ostream &os, Vector2 <T> &p)
{
    os << "Vector2 -- x: " << p.x << ", y: " << p.y << std::endl;

    return os;
}
#endif