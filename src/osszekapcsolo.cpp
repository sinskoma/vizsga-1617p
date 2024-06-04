#include "osszekapcsolo.hpp"

using namespace genv;
using namespace std;

Osszekapcsolo::Osszekapcsolo(int x_, int y_, vector<Ablak::Elem*>& elemek_) : Widget(x_, y_), nyil(x_, y_), oldal(x_, y_), valasztva(x_, y_, " ", 0), lista(false), gorgo(0), elemek(elemek_) {}

void Osszekapcsolo::rajzol()
{
    if (!lista&&elemek.size()>=4) {gout << color(0, 0, 0) << move_to(x, y) << box(500, 500);}
    valasztva.rajzol();
    nyil.rajzol();
}

void Osszekapcsolo::esemenyKezeles(event ev)
{
    if (valasztva.rajta(ev.pos_x, ev.pos_y)&&elemek.size()>=4)
    {
        if (lista)
        {
            if (ev.keycode == key_up || ev.button == btn_wheelup || (oldal.felsofelett(ev.pos_x, ev.pos_y) && ev.button == btn_left)) {gorgo--;}
            if (ev.keycode == key_down || ev.button == btn_wheeldown || (oldal.alsofelett(ev.pos_x, ev.pos_y) && ev.button == btn_left)) {gorgo++;}
            if (gorgo < 0) {gorgo = 0;}
            else if (gorgo > elemek.size() - 4) {gorgo = elemek.size() - 4;}
            for (int i = 0 + gorgo; i < gorgo + 4; i++)
            {
                Lista l(x, y, i - gorgo, elemek[i]->nev, elemek[i]->ertek);
                l.felette(ev.pos_x, ev.pos_y);
                l.rajzol();
                if (l.kijelolki() && ev.button == btn_left)
                {
                    valasztva = Valasztva(x, y, elemek[i]->nev, elemek[i]->ertek);
                    lista = false;
                    id=i;
                }
            }
            oldal.rajzol(elemek.size(), gorgo);
        }
    }
    if (nyil.rajta(ev.pos_x, ev.pos_y) && ev.button == btn_left&&elemek.size()>=4) {lista = !lista;}
}

bool Osszekapcsolo::rajta(int egerx, int egery)
{
    if (nyil.rajta(egerx, egery) || valasztva.rajta(egerx, egery)) {return true;}
    return false;
}
int Osszekapcsolo::idki() {return id;}
string Osszekapcsolo::valasztottki() {return valasztva.szovegki();}
