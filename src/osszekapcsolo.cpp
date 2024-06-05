#include "osszekapcsolo.hpp"

using namespace genv;
using namespace std;

Osszekapcsolo::Osszekapcsolo(int x_, int y_, vector<Ablak::Elem*>& elemek_) : Widget(x_, y_), valasztva(x_, y_, " "), elemek(elemek_) {id=-1;}

void Osszekapcsolo::rajzol()
{
    gout << color(0, 0, 0) << move_to(x, y+(elemek.size()+1)*80) << box_to(x+450,999);
    valasztva.rajzol();
}

void Osszekapcsolo::esemenyKezeles(event ev)
{
    for (int i = 0; i < elemek.size(); i++)
    {
        Lista l(x, y, i, elemek[i]->nev, elemek[i]->ertek);
        l.felette(ev.pos_x, ev.pos_y);
        l.rajzol();
        if (l.kijelolki() && ev.button == btn_left)
        {
            id=i;
        }
    }
    if(id!=-1) {valasztva = Valasztva(x, y, elemek[id]->nev);}
}

bool Osszekapcsolo::rajta(int egerx, int egery)
{
    if (valasztva.rajta(egerx, egery)) {return true;}
    return false;
}
int Osszekapcsolo::idki() {return id;}
