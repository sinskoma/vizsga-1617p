#ifndef MEZO_HPP
#define MEZO_HPP
#include "widget.hpp"
#include "graphics.hpp"

class Mezo:public Widget
{
    protected:
        int sor, oszlop, m, tipus, idg;
    public:
        Mezo(int x_, int y_, int meret, int tipus_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        void tipusbe(int t);
        int tipuski();
        int sorki();
        int oszlopki();
        virtual ~Mezo();
};

#endif // MEZO_HPP
