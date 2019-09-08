#include "PixelBuff.hpp"

PixelBuff::PixelBuff(unsigned w, unsigned h) : _width(w), _height(h)
{
    _pixels = vector<Uint32>(w * h, 0);
};

void PixelBuff::putPix(unsigned x, unsigned y, Uint32 col = 0xffffff)
{
    _pixels[x + (y * _width)] = col;
}

PixelBuff::~PixelBuff()
{
}

void PixelBuff::clear(void)
{
    fill(_pixels.begin(), _pixels.end(), 0);
}

PixelBuff::PixelBuff(PixelBuff const &origin)
    : _width(origin._width),
    _height(origin._height),
    _pixels(vector<Uint32>(origin._pixels))
     {}

PixelBuff &PixelBuff::operator=(PixelBuff const &rhs)
{
    if (this != &rhs)
    {
        PixelBuff(rhs).swap(*this);
    }

    return (*this);
}

vector<Uint32> &PixelBuff::getPixels()
{
    return (_pixels);
}

void PixelBuff::swap(PixelBuff &rhs)
{
    std::swap(_pixels, rhs._pixels);
    std::swap(_width, rhs._width);
    std::swap(_height, rhs._height);
}
std::ostream &operator<<(std::ostream &os, const PixelBuff &p)
{

    vector<Uint32>::const_iterator it;
    int i = 0;
    os << "WIDTH: " << p._width << " / HEIGHT: " << p._height;
    for (it = p._pixels.begin(); it != p._pixels.end(); it++, i++)
    {
        if (i % WIDTH == 0)
            os << std::endl;
        os << *it << " ";
    }

    os << std::endl;
    return os;
}
