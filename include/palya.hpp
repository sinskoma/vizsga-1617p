#ifndef PALYA_HPP
#define PALYA_HPP
#include "ablak.hpp"
#include "widget.hpp"
#include "graphics.hpp"
#include "JatekMester.hpp"

class JatekMester;

class Palya : public Ablak
{
    protected:
        int db, soros, meret; std::vector<Widget*> m; JatekMester* jatek;
    public:
        Palya(int XX_, int YY_, int darab, int soros);
        void rajzol() override;
        void esemenyKezeles(genv::event ev) override;
        virtual ~Palya();
};

#endif // PALYA_HPP
