#include "lista.hpp"

using namespace genv;
using namespace std;

Lista::Lista(int x_, int y_, int s, string sz, int osszeg_) : x(x_), y(y_), sorszam(s), szoveg(sz), osszeg(osszeg_) {
    gorgo = 0;
    sorszam++;
    hossz = 450;
    mag = 100;
    y += sorszam * mag + 1;
    kijelol = false;
}

void Lista::rajzol() {
    canvas c(hossz, mag);
    c << move_to(0, 0) << color(255, 255, 255) << box(hossz, mag) << move_to(2, 2);
    if (!kijelol) {
        c << color(200, 200, 200);
    } else {
        c << color(255, 200, 200);
    }
    c << box_to(hossz - 3, mag - 3) << move_to(20, 20) << font("LiberationSans-Regular.ttf", 50) << color(0, 0, 0) << text(szoveg)<<
    move_to(hossz-20-gout.twidth(to_string(osszeg)),20)<<text(to_string(osszeg));
    gout << stamp(c,x,y);
}

void Lista::felette(int egerx, int egery) {
    if (egerx > x && egerx < x + hossz && egery > y && egery < y + mag) {kijelol = true;}
    else{kijelol = false;}
}

bool Lista::kijelolki() {
    return kijelol;
}
