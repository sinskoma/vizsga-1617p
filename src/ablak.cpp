#include "ablak.hpp"
#include "szamlalo.hpp"
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
    gout<<font("LiberationSans-Regular.ttf",50)<<move_to(200,100+gout.cascent()/2)<<text("Mennyiseg:");
    Widget* szam=new szamlalo(500,100,300,100,1,10);
    v.push_back(szam);
    Widget* gomb=new button(50,300);
    v.push_back(gomb);
    Widget* lis=new Osszekapcsolo(250,450,e);
    v.push_back(lis);
    Widget* feltolt=new Torol(550,300);
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
        if(ossze&&sz&&kiad&&kiad->hozzaadki()) {e[ossze->idki()]->ertek-=sz->aktualiski();}
        if(ossze&&sz&&kiad&&felt->torles())
        {
            for(auto a:e) {a->ertek=10;}
        }
        gout<<refresh;
    }
}

void Ablak::esemenyKezeles(event ev) {}
