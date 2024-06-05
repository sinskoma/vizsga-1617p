#include "button.hpp"

using namespace std;
using namespace genv;

button::button(int x_, int y_, int sz_, int m_, string szoveg_):Widget(x_,y_), sz(sz_), m(m_), szoveg(szoveg_) {lenyomva=false;}

bool button::rajta(int egerx, int egery)
{
    if(x<egerx&&x+sz>egerx&&y<egery&&y+m>egery) {kijelol=true;}
    else{kijelol=false;}
}
void button::rajzol()
{
    canvas c(sz,m);
    if(kijelol) {c<<color(255,100,100);}
    else{c<<color(81,81,81);}
    c<<font("LiberationSans-Regular.ttf",m/2)<<move_to(0,0)<<box(sz,m)<<color(255,255,255)<<move_to(sz/2-gout.twidth(szoveg)/2,m/5)<<text(szoveg);
    gout<<stamp(c,x,y);
}

void button::esemenyKezeles(event ev)
{
    rajta(ev.pos_x,ev.pos_y);
    if(kijelol&&ev.button==btn_left){lenyomva=true;}
    else{lenyomva=false;}
}

bool button::lenyomvaki(){return lenyomva;}
button::~button() {}
