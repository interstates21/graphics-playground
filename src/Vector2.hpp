#ifndef V2_HPP
#define V2_HPP

#include "main.hpp"
#include "PixelBuff.hpp"
template <typename T>
class Vector2
{

public:
    explicit Vector2();
    void render();
    T x;
    T y;

    Vector2(T, T);
    Vector2<T> &operator++();
    Vector2<T> &operator++(int);
    Vector2<T> operator-() const;
    Vector2<T> operator+(const Vector2 <T> &other) const;
    Vector2<T> operator-(const Vector2 <T>&other) const;
    Vector2<T> operator*(T scalar) const;
    T operator*(const Vector2 <T>&rhs) const;
    Vector2 <T>cross(const Vector2 <T>&rhs) const;
    operator bool() const;

    void render(PixelBuff &) const;
    friend std::istream &operator>>(std::istream &is, Vector2 <T> &p);
    friend std::ostream &operator<<(std::ostream &os, Vector2 <T> &p);
private:
};

#endif