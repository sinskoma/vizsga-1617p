#include "ablak.hpp"
#include "szamlalo.hpp"
#include "szoveg.hpp"
#include "button.hpp"
#include "osszekapcsolo.hpp"
#include "torol.hpp"

using namespace genv;
using namespace std;

Ablak::Ablak(int XX_, int YY_): XX(XX_), YY(YY_) {egyenleg=0;}

Ablak::~Ablak()
{
    for(auto widget : v) {delete widget;}
}

void Ablak::rajzol()
{
    event ev;
    gout.open(XX,YY);
    Widget* szam=new szamlalo(100,100,300,100,0,10);
    v.push_back(szam);
    Widget* gomb=new button(350,300);
    v.push_back(gomb);
    Widget* lis=new Osszekapcsolo(250,500,e);
    v.push_back(lis);
    Widget* feltolt=new Torol(700,300);
    v.push_back(feltolt);
    string alapanyag[5]={"vanilia","tutti-frutti","karamell","rumosodo","kave"};
    for(int i=0;i<5;i++)
    {
        Elem* idg=new Elem(alapanyag[i],10);
        e.push_back(idg);
    }
    while(gin>>ev&&ev.keycode!=key_escape)
    {
        for(auto a:v)
        {
            a->rajzol();
            a->esemenyKezeles(ev);
        }
        button* kiad=dynamic_cast<button*>(gomb);
        Torol* felt=dynamic_cast<Torol*>(feltolt);
        szamlalo* sz=dynamic_cast<szamlalo*>(szam);
        Osszekapcsolo* ossze=dynamic_cast<Osszekapcsolo*>(lis);
        gout<<refresh;
    }
}

void Ablak::esemenyKezeles(event ev) {}
