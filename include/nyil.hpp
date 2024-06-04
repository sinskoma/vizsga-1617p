#ifndef NYIL_HPP
#define NYIL_HPP

#include "graphics.hpp"

class Nyil {
private:
    int x, y, meret;

public:
    Nyil(int x_, int y_);
    void rajzol();
    bool rajta(int egerx, int egery);
};

#endif // NYIL_HPP
