#include "menugomb.hpp"

using namespace genv;
using namespace std;

Menugomb::Menugomb(int x_, int y_, int ti):Widget(x_, y_), tipus(ti) {m=200;kijelolve=false;vastagsag=5;}
Menugomb::~Menugomb() {}
void Menugomb::rajzol()
{
    canvas c(300,300);
    if(tipus==0)
    {
        for(int i=0;i<vastagsag;i++)
        {
            c<<move_to(0,i)<<color(255,0,0)<<line_to(m-i,m)<<move_to(i,0)<<line_to(m,m-i)
            <<move_to(m-i,0)<<line_to(0,m-i)<<move_to(m,i)<<line_to(i,m);
        }
    }
    else if(tipus==1)
    {
        for (int i=0;i<=200;i++)
        {
            for (int j=0;j<=200;j++)
            {
                if (abs((i-100)*(i-100)+(j-100)*(j-100)-95*95)<=vastagsag*100)
                {
                    c<<move_to(i,j)<<color(101,147,245)<<dot;
                }
            }
        }
    }
    gout<<stamp(c,x,y);
}

bool Menugomb::rajta(int egerx, int egery)
{
    if(x<egerx&&x+m>egerx&&y<egery&&y+m>egery) {return true;}
    else{return false;}
}
bool Menugomb::kijelolveki() {return kijelolve;}
int Menugomb::tipuski() {return tipus;}
void Menugomb::esemenyKezeles(event ev)
{
    if(rajta(ev.pos_x,ev.pos_y)) {vastagsag=10;}
    else{vastagsag=5;}
    rajzol();
    if(ev.button==btn_left&&rajta(ev.pos_x,ev.pos_y)) {kijelolve=true;}
}
