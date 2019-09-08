#ifndef LINE_HPP
#define LINE_HPP

#include "V2.hpp"
#include "PixelBuff.hpp"
#include "APrimitive.hpp"


template <typename P>
class Line : public APrimitive{


    public:

    Line(P, P);

    render(PixelBuff &);

    private:
};

#endif