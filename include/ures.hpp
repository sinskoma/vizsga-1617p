#ifndef TORL_HPP
#define TOROL_HPP
#include "widget.hpp"
#include "graphics.hpp"

class ures:public Widget
{
    protected:
        int sz,m; bool kijelol, mehet; std::string szoveg;
    public:
        ures(int x_, int y_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        bool mehetki();
        virtual ~ures();
};

#endif // TOROL_HPP
