#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include "graphics.hpp"

class button:public Widget
{
    protected:
        int sz,m; bool kijelol, hozzaad; std::string szoveg;
    public:
        button(int x_, int y_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        bool hozzaadki();
        virtual ~button();
};

#endif // BUTTON_HPP
