#include "szoveg.hpp"
#include <iostream>

using namespace std;
using namespace genv;

Szoveg::Szoveg(int x_, int y_, int sz_, int m_, string tartalom_):Widget(x_, y_), t(tartalom_), box_sz(sz_), box_m(m_)
{
    gout<<font("LiberationSans-Regular.ttf",box_m/2);
    sz=gout.twidth(t); m=gout.cdescent()+gout.cascent();
    kijelolve=false;
}

Szoveg::~Szoveg() {}

void Szoveg::rajzol()
{
    gout << move_to(x, y) << color(81, 81, 81) << box(box_sz,box_m);
    gout << move_to(x+box_sz/2-sz/2, y+25) << color(255, 255, 255) << text(t);
    if (kijelolve) {kurzor();}
    if(sz<300) {gout<<color(81,81,81)<<move_to(x+sz+30,y)<<box(30,box_m);}
}

bool Szoveg::rajta(int egerx, int egery)
{
    if(x<egerx&&x+box_sz>egerx&&y<egery&&y+box_m>egery) {return true;}
    else{return false;}
}

void Szoveg::esemenyKezeles(event ev)
{
    cout<<sz<<endl;
    if (ev.type == ev_mouse && ev.button == btn_left)
    {
        if (rajta(ev.pos_x, ev.pos_y)) {kijelolve = true;}
        else{kijelolve = false;}
    }
    if (kijelolve)
    {
        kurzor();
        if (ev.type == ev_key)
        {
            if (ev.keycode==key_backspace&&t.length()>0) {t.pop_back();}
            else if (ev.keycode<255&&ev.keycode>=20&&sz<300) {t+=ev.keycode;}
            sz=gout.twidth(t);
        }
    }
    rajzol();
}
string Szoveg::tki() {return t;}
void Szoveg::kurzor() {gout<<color(255,255,255)<<move_to(x+box_sz/2+sz/2+5,y+10)<<box_to(x+box_sz/2+sz/2+5+3,y+box_m-10);}
