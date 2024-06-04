#include "ures.hpp"

using namespace std;
using namespace genv;

ures::ures(int x_, int y_):Widget(x_,y_), sz(250), m(100), szoveg("Ures") {mehet=false;}

bool ures::rajta(int egerx, int egery)
{
    if(x<egerx&&x+sz>egerx&&y<egery&&y+m>egery) {kijelol=true;}
    else{kijelol=false;}
}
void ures::rajzol()
{
    canvas c(sz,m);
    if(kijelol) {c<<color(255,100,100);}
    else{c<<color(81,81,81);}
    c<<font("LiberationSans-Regular.ttf",50)<<move_to(0,0)<<box(sz,m)<<color(255,255,255)<<move_to(sz/2-gout.twidth(szoveg)/2,20)<<text(szoveg);
    gout<<stamp(c,x,y);
}

void ures::esemenyKezeles(event ev)
{
    rajta(ev.pos_x,ev.pos_y);
    if(kijelol&&ev.button==btn_left){mehet=true;}
    else{mehet=false;}
}

bool ures::mehetki(){return mehet;}
ures::~ures() {}