#ifndef LINE_HPP
#define LINE_HPP

#include "Vector2.hpp"
#include "main.hpp"
#include "PixelBuff.hpp"
#include "APrimitive.hpp"

class Line
{

public:
    Line();
    Line(int p1_x, int p1_y, int p2_x, int p2_y);
    Line(Vector2 <int> const & a, Vector2 <int> const & b);
    void render(PixelBuff &buff, Uint32 color);
    Vector2 <int> p1;
    Vector2 <int> p2;

    void render(PixelBuff &);

private:
};

#endif