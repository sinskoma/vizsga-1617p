#include "ablak.hpp"
#include "szamlalo.hpp"
#include "szoveg.hpp"
#include "button.hpp"
#include "osszekapcsolo.hpp"
#include "torol.hpp"
#include "ures.hpp"

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
    Widget* szam=new szamlalo(100,100,300,100,-1000,1000);
    v.push_back(szam);
    Widget* szoveg=new Szoveg(500,100,"");
    v.push_back(szoveg);
    Widget* gomb=new button(350,300);
    v.push_back(gomb);
    Widget* lis=new Osszekapcsolo(250,500,e);
    v.push_back(lis);
    Widget* torol=new Torol(700,300);
    v.push_back(torol);
    Widget* urit=new ures(50,300);
    v.push_back(urit);
    while(gin>>ev&&ev.keycode!=key_escape)
    {
        for(auto a:v)
        {
            a->rajzol();
            a->esemenyKezeles(ev);
        }
        button* b=dynamic_cast<button*>(gomb);
        Torol* tor=dynamic_cast<Torol*>(torol);
        szamlalo* szaidg=dynamic_cast<szamlalo*>(szam);
        Szoveg* szoidg=dynamic_cast<Szoveg*>(szoveg);
        Osszekapcsolo* ossze=dynamic_cast<Osszekapcsolo*>(lis);
        ures* ur=dynamic_cast<ures*>(urit);
        if(b && b->hozzaadki()&&szaidg&&szoidg)
        {
            Elem* idg=new Elem(szoidg->tki(),szaidg->aktualiski());
            e.push_back(idg);
        }
        if(tor&&tor->torles()&&ossze) {e.erase(e.begin()+ossze->idki());}
        if(ur&&ur->mehetki()&&ossze) {e.erase(e.begin(),e.end());}
        egyenleg=0;
        for(auto a:e) {egyenleg+=a->ertek;}
        egyenlegrajzol();
        gout<<refresh;
    }
}

void Ablak::egyenlegrajzol()
{
    canvas c(1000,100);
    c<<font("LiberationSans-Regular.ttf",50)<<move_to(0,0)<<color(0,0,0)<<box(1000,100)<<
    color(255,255,255)<<move_to(500-gout.twidth("Egyenleg: "+to_string(egyenleg))/2,20)<<text("Egyenleg: "+to_string(egyenleg));
    gout<<stamp(c,0,400);
}

void Ablak::esemenyKezeles(event ev) {}
