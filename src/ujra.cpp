#include "ujra.hpp"

using namespace genv;

Ujra::Ujra(int x_, int y_):Widget(x_,y_) {sz=400; m=100;}

Ujra::~Ujra() {}

void Ujra::rajzol()
{
    gout<<move_to(1000,0)<<color(0,0,0)<<box_to(1759,450)<<color(255,255,255)<<move_to(1200,300)<<font("LiberationSans-Regular.ttf",50)<<text("A nyertes jatekos:")<<refresh;
    canvas c(sz,m);
    if(kijelolve) {c<<color(250,100,100);}
    else{c<<color(81,81,81);}
    c<<move_to(0,0)<<box(sz,m)<<move_to(sz/2-gout.twidth("Ujrakezdes")/2,20)<<color(255,255,255)<<font("LiberationSans-Regular.ttf",50)<<text("Ujrakezdes");
    gout<<stamp(c,x,y);
}

bool Ujra::rajta(int egerx, int egery)
{
    if(x<egerx&&x+sz>egerx&&y<egery&&y+m>egery) {return true;}
    else{return false;}
}

void Ujra::esemenyKezeles(event ev)
{
    while(gin>>ev&&ev.keycode!=key_escape)
    {
        if(rajta(ev.pos_x,ev.pos_y)) {kijelolve=true;}
        else{kijelolve=false;}
        rajzol();
        if(kijelolve&&ev.button==btn_left) {break;}
    }
    if(ev.keycode==key_escape) {exit(0);}
}
