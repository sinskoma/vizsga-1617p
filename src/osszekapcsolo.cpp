#include "osszekapcsolo.hpp"

using namespace genv;
using namespace std;

Osszekapcsolo::Osszekapcsolo(int x_, int y_, vector<Ablak::Elem*>& elemek_) : Widget(x_, y_), nyil(x_, y_), oldal(x_, y_), valasztva(x_, y_, " "), lista(false), gorgo(0), elemek(elemek_) {}

void Osszekapcsolo::rajzol()
{
    gout << color(0, 0, 0) << move_to(x, y) << box(500, 620);
    valasztva.rajzol();
}

void Osszekapcsolo::esemenyKezeles(event ev)
{
    for (int i = 0; i < elemek.size(); i++)
    {
        Lista l(x, y, i - gorgo, elemek[i]->nev, elemek[i]->ertek);
        l.felette(ev.pos_x, ev.pos_y);
        l.rajzol();
        if (l.kijelolki() && ev.button == btn_left)
        {
            valasztva = Valasztva(x, y, elemek[i]->nev);
            lista = false;
            id=i;
        }
    }
}

bool Osszekapcsolo::rajta(int egerx, int egery)
{
    if (nyil.rajta(egerx, egery) || valasztva.rajta(egerx, egery)) {return true;}
    return false;
}
int Osszekapcsolo::idki() {return id;}
