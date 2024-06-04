#ifndef TORL_HPP
#define TOROL_HPP
#include "widget.hpp"
#include "graphics.hpp"

class Torol:public Widget
{
    protected:
        int sz,m; bool kijelol, hozzaad; std::string szoveg;
    public:
        Torol(int x_, int y_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        bool torles();
        virtual ~Torol();
};

#endif // TOROL_HPP
