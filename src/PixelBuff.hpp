#ifndef DRAWER_HPP
#define DRAWER_HPP

#include "main.hpp"
#include <algorithm>
#include <vector>

using namespace std;

class PixelBuff
{
public:
    PixelBuff(unsigned, unsigned);

    PixelBuff &operator=(PixelBuff const &);
    vector<Uint32> &getPixels(void);
    void putPix(unsigned, unsigned, Uint32);
    void clear(void);
    ~PixelBuff();

    friend std::ostream &operator<<(std::ostream &stream, const PixelBuff &matrix);

private:
    int _width;
    int _height;
    vector<Uint32> _pixels;
};

#endif
