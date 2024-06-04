#include "mezo.hpp"

using namespace genv;

Mezo::Mezo(int x_, int y_, int meret, int tipus_):Widget(x_, y_), m(meret), tipus(tipus_)
{
    sor=x; oszlop=y; x=sor*m; y=oszlop*m;
}

Mezo::~Mezo() {}

void Mezo::rajzol()
{
    canvas negyzet(m,m);
    negyzet<<color(0,255,255)<<move_to(0,0)<<box(m,m)<<move_to(2,2)<<color(0,0,0)<<box_to(m-3,m-3);
    if(tipus==1)
    {
        for(int i=0;i<5;i++)
        {
            negyzet<<move_to(3,i+3)<<color(255,0,0)<<line_to(m-i-3,m-3)<<move_to(i+3,3)<<line_to(m-3,m-i-3)
            <<move_to(m-i-3,3)<<line_to(3,m-i-3)<<move_to(m-3,i+3)<<line_to(i+3,m-3);
        }
    }
    if(tipus==2)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(abs((i-m/2)*(i-m/2)+(j-m/2)*(j-m/2)-(m/2-5)*(m/2-5))<=(200-100/66.66*(3*(66,66-m)))) {negyzet<<move_to(i,j)<<color(101,147,245)<<dot;}
            }
        }

    }
    gout<<stamp(negyzet,x,y);
}
bool Mezo::rajta(int egerx, int egery)
{
    if(x<egerx&&x+m>egerx&&y<egery&&y+m>egery) {return true;}
    else{return false;}
}
void Mezo::tipusbe(int t) {idg=t;}
int Mezo::tipuski() {return tipus;}
int Mezo::sorki() {return sor;}
int Mezo::oszlopki() {return oszlop;}
void Mezo::esemenyKezeles(event ev)
{
    if(rajta(ev.pos_x,ev.pos_y)&&ev.button==btn_left&&tipus==0) {tipus=idg;}
}
