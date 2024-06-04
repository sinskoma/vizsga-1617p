#ifndef UJRA_HPP
#define UJRA_HPP
#include "widget.hpp"
#include "graphics.hpp"

class Ujra:public Widget
{
    protected:
        int sz,m; bool kijelolve;
    public:
        Ujra(int x_, int y_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        virtual ~Ujra();
};

#endif // UJRA_HPP
