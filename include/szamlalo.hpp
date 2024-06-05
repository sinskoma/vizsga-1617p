#ifndef SZAMALLO_HPP
#define SZAMALLO_HPP

#include "widget.hpp"
#include "graphics.hpp"

class szamlalo : public Widget
{
protected:
    int box_x, box_y, box_y2, box_meret,sz,m,aktualis,alhat,felhat; bool kijelolve;
public:
    szamlalo(int x_, int y_, int sz_, int m_, int alsohatar, int felsohatar);
    void rajzol() override;
    void hatarok();
    bool rajta(int egerx, int egery) override;
    bool rajta2(int egerx, int egery);
    bool rajta3(int egerx, int egery);
    void esemenyKezeles(genv::event ev) override;
    int aktualiski();
    ~szamlalo() {}
};

#endif // SZAMLALO_HPP
