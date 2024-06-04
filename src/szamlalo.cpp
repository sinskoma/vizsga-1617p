#include "szamlalo.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

szamlalo::szamlalo(int x_, int y_, int sz_, int m_, int alsohatar, int felsohatar) : Widget(x_, y_), sz(sz_), m(m_), alhat(alsohatar), felhat(felsohatar)
{
    box_meret = 40;
    box_x = x+sz-50;
    box_y =y+5;
    box_y2 = box_y + m/2;
    aktualis=15;
}

void szamlalo::rajzol()
{
    gout << move_to(x, y) << color(255, 255, 255) << box(sz, m)
         << move_to(x + 1, y + 1) << color(255, 255, 255) << box(sz - 2, m - 2)
         << color(0, 0, 0) << move_to(x+sz/2-gout.twidth(to_string(aktualis))/2-20,y+20) <<font("LiberationSans-Regular.ttf",50)<< text(to_string(aktualis));

    canvas c(box_meret + 1, box_meret + 1);
    c << move_to(0, 0) << color(80, 80, 80) << box(box_meret, box_meret) << color(0, 0, 0);
    for (int i = 0; i <= 15; i++) {
        c << move_to(box_meret / 2 - i, box_meret / 4 + i) << line_to(box_meret / 2 + i, box_meret / 4 + i);
    }
    gout << stamp(c, box_x, box_y);
    c << move_to(0, 0) << color(80, 80, 80) << box(box_meret, box_meret) << color(0, 0, 0);
    for (int i = 15; i >= 0; i--) {
        c << move_to(box_meret / 2 - i, box_meret / 4 + 20 - i) << line_to(box_meret / 2 + i, box_meret / 4 + 20 - i);
    }
    gout << stamp(c, box_x, box_y2);
}

bool szamlalo::rajta(int egerx, int egery)
{
    if (x < egerx && x + sz > egerx && y < egery && y + m > egery) {return true;}
    else {return false;}
}

bool szamlalo::rajta2(int egerx, int egery)
{
    if (box_x < egerx && box_x + box_meret > egerx && box_y < egery && box_y + box_meret > egery) {return true;}
    else {return false;}
}

bool szamlalo::rajta3(int egerx, int egery)
{
    if (box_x < egerx && box_x + box_meret > egerx && box_y2 < egery && box_y2 + box_meret > egery) {return true;}
    else {return false;}
}
void szamlalo::hatarok()
{
    if(alhat>aktualis) {aktualis=alhat;}
    else if(felhat<aktualis) {aktualis=felhat;}
}
void szamlalo::esemenyKezeles(event ev)
{
    rajzol();
    if (rajta(ev.pos_x, ev.pos_y)||ev.type==ev_key)
    {
        if (ev.keycode == key_up || ev.button == btn_wheelup || (rajta2(ev.pos_x, ev.pos_y) && ev.button == btn_left)) {aktualis++;}
        else if (ev.keycode == key_down || ev.button == btn_wheeldown || (rajta3(ev.pos_x, ev.pos_y) && ev.button == btn_left)) {aktualis--;}
        else if (ev.keycode == key_pgup) {aktualis += 100;}
        else if (ev.keycode == key_pgdn) {aktualis -= 100;}
    }
    hatarok();
}
int szamlalo::aktualiski() {return aktualis;}
