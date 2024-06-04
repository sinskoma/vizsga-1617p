#ifndef VALASZTVA_HPP
#define VALASZTVA_HPP

#include "graphics.hpp"

class Valasztva
{
protected:
    int x, y, hossz, mag;
    std::string szoveg;

public:
    Valasztva(int x_, int y_, std::string s);
    void rajzol();
    bool rajta(int egerx, int egery);
};

#endif // VALASZTVA_HPP
