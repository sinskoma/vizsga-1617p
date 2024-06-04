#include "Oldal.hpp"
#include "graphics.hpp"

using namespace genv;

Oldal::Oldal(int x_, int y_) : x(x_), y(y_) { x += 450; y += 100; szel = 49; mag = 400; meret = 45; }

void Oldal::rajzol(int oszto, int poz) {
    genv::canvas c(szel, mag);
    c << move_to(0, 0) << color(128, 128, 128) << box(szel, mag);
    genv::canvas fent(meret, meret); genv::canvas lent(meret, meret);

    fent << move_to(0, 0) << move_to(0, 0) << color(200, 200, 200) << box(45, 45) << color(0, 0, 0);
    for (int i = 0; i <= meret / 3; i++) { fent << move_to(meret / 2 - i, meret / 2 + i - 10) << line_to(meret / 2 + i, meret / 2 + i - 10); }
    c << stamp(fent, 2, 2);

    lent << move_to(0, 0) << move_to(0, 0) << color(200, 200, 200) << box(45, 45) << color(0, 0, 0);
    for (int i = meret / 3; i >= 0; i--) { lent << move_to(meret / 2 - i, meret / 2 - i + 10) << line_to(meret / 2 + i, meret / 2 - i + 10); }
    c << stamp(lent, szel - meret - 2, mag - meret - 2);

    int *vmag = new int(mag - meret * 2 - 8);
    genv::canvas vonal(szel, *vmag);
    vonal << move_to(0, 0) << color(85, 85, 85) << box(szel, *vmag);
    c << stamp(vonal, 0, meret + 4);

    int mozgo_mag=*vmag / oszto * 4;

    canvas mozgo(szel, mozgo_mag);
    mozgo << move_to(0, 0) << color(211, 211, 211) << box_to(szel - 1, mozgo_mag - 3);
    int mozgo_poz;
    if(oszto!=4) mozgo_poz = 6 + meret + poz * ((*vmag - mozgo_mag)/(oszto-4));
    else{mozgo_poz=meret+6;}
    c << stamp(mozgo, 0, mozgo_poz);
    gout << stamp(c, x, y);
}


bool Oldal::felsofelett(int egerx, int egery) {
    if (x + 2 < egerx && x + 2 + meret > egerx && y + 2 < egery && y + 2 + meret > egery) { return true; }
    else { return false; }
}

bool Oldal::alsofelett(int egerx, int egery) {
    if (x + szel - meret - 4 < egerx && x + szel > egerx && y + mag - meret - 4 < egery && y + mag > egery) { return true; }
    else { return false; }
}
