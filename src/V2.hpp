#ifndef V2_HPP
#define V2_CPP

template <typename T>
class V2
{

public:
    explicit V2();
    void render();
    T x;
    T y;

    V2 operator+(V2 const &other);

private:
};

#endif