#if !defined(APRIMITIVE_HPP)
#define APRIMITIVE_HPP

#include "PixelBuff.hpp"

class APrimitive
{
public:
    APrimitive();

    virtual void render(PixelBuff &) = 0;
    ~APrimitive();

private:
    /* data */
};

#endif // APRIMITIVE_HPP
