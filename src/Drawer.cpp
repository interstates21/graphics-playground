#include "Drawer.hpp"

Drawer::Drawer() : _width(WIDTH), _height(HEIGHT){};

Drawer::Drawer(int w, int h) : _width(w), _height(h)
{
    _pixels.assign(w * h, 0);
};

Drawer::~Drawer()
{
}

void Drawer::putPix(unsigned x, unsigned y, Uint32 col = 0xffffff)
{
    _pixels[x * WIDTH * y] = col;
}

void Drawer::clearPixels(void)
{
    fill(_pixels.begin(), _pixels.end(), 0);
}

vector<Uint32> const &Drawer::getPixels()
{
    return (_pixels);
}
Drawer::Drawer