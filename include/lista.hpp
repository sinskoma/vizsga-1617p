#ifndef LISTA_HPP
#define LISTA_HPP

#include "graphics.hpp"

class Lista {
private:
    int x, y, hossz, mag, sorszam, osszeg;
    bool kijelol;
    std::string szoveg;

public:
    Lista(int x_, int y_, int s, std::string sz, int osszeg_);
    void rajzol();
    void felette(int egerx, int egery);
    bool kijelolki();
};

#endif // LISTA_HPP
