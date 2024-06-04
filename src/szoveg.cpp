#include "szoveg.hpp"
#include <iostream>
using namespace std;
using namespace genv;

Szoveg::Szoveg(int x_, int y_, string tartalom_):Widget(x_, y_), t(tartalom_)
{
    gout<<font("LiberationSans-Regular.ttf",50);
    sz=gout.twidth(t); m=gout.cdescent()+gout.cascent();
    kijelolve=false;
    box_sz=400;
    box_m=100;
}

Szoveg::~Szoveg() {}

void Szoveg::rajzol()
{
    gout << move_to(x, y) << color(81, 81, 81) << box(box_sz,box_m);
    gout << move_to(x+20, y+25) << color(255, 255, 255) << text(t);
    if (kijelolve) {kurzor();}
    if(sz<box_sz-50) {gout<<color(81,81,81)<<move_to(x+sz+30,y)<<box(30,box_m);}
}

bool Szoveg::rajta(int egerx, int egery)
{
    if(x<egerx&&x+box_sz>egerx&&y<egery&&y+box_m>egery) {return true;}
    else{return false;}
}

void Szoveg::esemenyKezeles(event ev)
{
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
            else if (ev.keycode < 255 && ev.keycode >= 20&&sz<box_sz-50) {t += ev.keycode;}
            sz=gout.twidth(t);
        }
    }
    rajzol();
}
string Szoveg::tki() {return t;}
void Szoveg::kurzor() {gout<<color(255,255,255)<<move_to(x+sz+25,y+10)<<box_to(x+sz+25+3,y+box_m-10);}
