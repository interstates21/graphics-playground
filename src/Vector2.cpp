
#include "Vector2.hpp"

template <typename T>
Vector2<T>::Vector2() : x(0), y(0) {}

template <typename T>
Vector2<T>::Vector2(T a, T b) : x(a), y(b) {}

template <typename T>
Vector2<T> &Vector2<T>::operator++()
{

    x += 1;
    y += 1;
    return (*this)
}

template <typename T>
Vector2<T> &Vector2<T>::operator++(int)
{

    Vector2<T> tmp(*this);

    ++(*this);

    return tmp;
}

template <typename T>
Vector2<T> Vector2<T>::operator-() const
{
    return (Vector2(-x, -y));
}

template <typename T>
Vector2<T> Vector2<T>::operator+(const Vector2 <T> &other) const
{
    return (Vector2(other.x + x, other.y + y));
}

template <typename T>
Vector2<T> Vector2<T>::operator-(const Vector2 <T>&other) const
{
    return (Vector2(other.x - x, other.y - y));
}

template <typename T>
Vector2<T> Vector2<T>::operator*(T scalar) const
{
    return (Vector2(x * scalar, y * scalar));
}


template <typename T>
T Vector2<T>::operator*(const Vector2 <T>&rhs) const
{
    return (Vector2((x * rhs.x) + (y * rhs.y)));
}

template <typename T>
Vector2 <T>Vector2<T>::cross(const Vector2 <T>&rhs) const
{
    Vector2 v;

    v.x = x * rhs.y;
    v.y = y * rhs.x;

    return (v);
}

template <typename T>
Vector2<T>::operator bool() const
{
    return (x != 0 && y != 0);
}

void render(PixelBuff &p) {
    PixelBuff.putPix((int)x, (int)y);
}

template <typename T>
std::istream &operator>>(std::istream &is, Vector2 <T> &p)
{
    is >> "Vector2 -- x: " << p.x << ", y: " << p.y << std::endl;

    return is;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, Vector2 <T> &p)
{
    os << "Vector2 -- x: " << p.x << ", y: " << p.y << std::endl;

    return os;
}