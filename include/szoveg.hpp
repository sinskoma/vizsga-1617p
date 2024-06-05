#ifndef SZOVEG_HPP
#define SZOVEG_HPP
#include "widget.hpp"
#include "graphics.hpp"

class Szoveg:public Widget
{
    protected:
        int sz, m, box_sz, box_m; std::string t; bool kijelolve;
    public:
        Szoveg(int x_, int y_, int sz_, int m_, std::string tartalom_);
        void rajzol() override;
        bool rajta(int egerx, int egery) override;
        void esemenyKezeles(genv::event ev) override;
        void kurzor();
        std::string tki();
        virtual ~Szoveg();
};

#endif // SZOVEG_HPP
