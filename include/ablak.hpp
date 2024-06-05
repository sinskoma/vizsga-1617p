#ifndef ABLAK_HPP_INCLUDED
#define ABLAK_HPP_INCLUDED

#include "graphics.hpp"
#include "szamlalo.hpp"
#include "widget.hpp"
#include <vector>

class Ablak {
public:
    struct Elem
    {
        std::string nev; int ertek;
        Elem(const std::string& n, int e) : nev(n), ertek(e) {}
    };
    Ablak(int XX_, int YY_);
    ~Ablak();
    virtual void rajzol();
    virtual void esemenyKezeles(genv::event ev);
    void egyenlegrajzol();
protected:
    const int XX, YY;
    int egyenleg;
    std::vector<Widget*> v;
    std::vector<Elem*> e;
    std::vector<Elem*> ar;
};

#endif // ABLAK_HPP_INCLUDED
