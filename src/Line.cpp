#include "Line.hpp"

Line::Line() : p1(Vector2 <int>()), p2(Vector2 <int>()) {}

Line::Line(int p1_x, int p1_y, int p2_x, int p2_y):
p1(Vector2<int>(p1_x, p1_y)),
p2(Vector2<int>(p2_x, p2_y)){}

Line::Line(Vector2 <int> const &a, Vector2 <int> const &b): p1(a), p2(b) {}

void Line::render(PixelBuff &buff, Uint32 color) {

    int stepDiff, x, y;
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);

    int stepX = p2.x >= p1.x ? 1 : -1;
    int stepY = p2.y >= p1.y ? 1 : -1;

    if (dx > dy) {
        stepDiff = (dy << 1) - dx;

        x = p1.x + stepX;
        y = p1.y;

        int i = 1;
        buff.putPix(x, y, color);

        while (i <= dx) {
            if (stepDiff > 0) {
                stepDiff += (dy - dx) << 1;
                y += stepY;
            }
            else {
                stepDiff += dy << 1;
            }

             buff.putPix(x, y, color);
             i++;
             x += stepX;
        }
    }

    else if (dx <= dy) {
        stepDiff = (dx << 1) - dy;
        x = p1.x;
        y = p1.y + stepY;
        int i = 1;

        buff.putPix(x, y, color);

        while (i <= dy) {
            if (stepDiff > 0) {
                stepDiff += (dx - dy) << 1;
                x += stepX;
            }
            else
                stepDiff += dx << 1;
             buff.putPix(x, y, color);
             i++;
             y += stepY;
        }

    } 
}
