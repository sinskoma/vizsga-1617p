#ifndef VALASZTVA_HPP
#define VALASZTVA_HPP

#include "graphics.hpp"

class Valasztva
{
protected:
    int x, y, hossz, mag, osszeg;
    std::string szoveg;

public:
    Valasztva(int x_, int y_, std::string s, int osszeg_);
    void rajzol();
    bool rajta(int egerx, int egery);
    std::string szovegki();
};

#endif // VALASZTVA_HPP
