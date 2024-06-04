#ifndef MENUGOMB_HPP
#define MENUGOMB_HPP
#include "widget.hpp"
#include "graphics.hpp"

class Menugomb : public Widget
{
    protected:
        int tipus, m, vastagsag; bool kijelolve;
    public:
        Menugomb(int x_, int y_, int ti);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        bool kijelolveki();
        int tipuski();
        virtual ~Menugomb();
};

#endif // MENUGOMB_HPP
