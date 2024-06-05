#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include "graphics.hpp"

class button:public Widget
{
    protected:
        int sz,m; bool kijelol, lenyomva; std::string szoveg;
    public:
        button(int x_, int y_, int sz_, int m_, std::string szoveg_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        bool lenyomvaki();
        virtual ~button();
};

#endif // BUTTON_HPP
