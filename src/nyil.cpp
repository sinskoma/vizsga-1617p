#include "nyil.hpp"

using namespace genv;

Nyil::Nyil(int x_, int y_) : x(x_), y(y_)
{
    meret = 50;
    x += 450;
}

void Nyil::rajzol() {
    canvas c(meret, meret * 2);
    c << color(80, 80, 80) << move_to(0, 0) << box(meret, meret * 2) << color(0, 0, 0);
    for (int i = meret / 3; i >= 0; i--) {c << move_to(meret / 2 - i, meret * 5 / 4 - i) << line_to(meret / 2 + i, meret * 5 / 4 - i);}
    gout << stamp(c, x, y);
}

bool Nyil::rajta(int egerx, int egery) {
    if (x < egerx && x + meret > egerx && y < egery && y + meret * 2 > egery) {return true;}
    else {return false;}
}
