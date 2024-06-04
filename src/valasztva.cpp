#include "Valasztva.hpp"

Valasztva::Valasztva(int x_, int y_, std::string s, int osszeg_) : x(x_), y(y_), szoveg(s), osszeg(osszeg_) {hossz = 500; mag = 100;}

using namespace genv;
using namespace std;

void Valasztva::rajzol() {
    canvas c(hossz, mag);
    c << move_to(0, 0) << color(255, 255, 255) << box(hossz, mag) << move_to(20, 20) << color(0, 0, 0) << font("LiberationSans-Regular.ttf", 50)
    << text(szoveg)<<move_to(hossz-70-gout.twidth(to_string(osszeg)),20)<<text(to_string(osszeg));
    gout << stamp(c, x, y);
}

bool Valasztva::rajta(int egerx, int egery)
{
    if (x < egerx && x + hossz > egerx && y < egery && y + 5 * mag > egery) { return true; }
    else {return false;}
}

std::string Valasztva::szovegki() {return szoveg;}
