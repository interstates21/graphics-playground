#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <algorithm>
#include "main.hpp"
#include <vector>

using namespace std;

class Drawer
{
public:
    Drawer();
    Drawer(unsigned, unsigned);

    vector<Uint32> &getPixels(void);
    void putPix(unsigned, unsigned, Uint32);
    void clearPixels(void);
    ~Drawer();

private:
    int _width;
    int _height;
    vector<Uint32> &_pixels;
};

#endif