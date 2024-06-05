#include "ablak.hpp"
#include "szamlalo.hpp"
#include "button.hpp"
#include "osszekapcsolo.hpp"
#include "szoveg.hpp"

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
    gout<<font("LiberationSans-Regular.ttf",50)<<move_to(20,50+gout.cascent()/2)<<text("Mennyiseg:");
    gout<<move_to(20,900)<<text("Egyenleg:");
    Widget* szam=new szamlalo(40+gout.twidth("Mennyiseg:"),50,300,100,1,10);
    v.push_back(szam);
    Widget* lis=new Osszekapcsolo(700,50,e);
    v.push_back(lis);
    Widget* aras=new Osszekapcsolo(1200,50,ar);
    v.push_back(aras);
    Widget* kiadas=new button(25,350,300,100,"Kiad");
    v.push_back(kiadas);
    Widget* feltolt=new button(25,500,300,100,"Feltolt");
    v.push_back(feltolt);
    Widget* atad=new button(350,350,300,100,"Atad");
    v.push_back(atad);
    Widget* hozzaad=new button(350,500,300,100,"Hozzaad");
    v.push_back(hozzaad);
    Widget* torol=new button(25,650,300,100,"Torles");
    v.push_back(torol);
    Widget* otorol=new button(350,650,300,100,"Ossztorles");
    v.push_back(otorol);
    Widget* szoveg=new Szoveg(25,200,625,100,"Irj ide...");
    v.push_back(szoveg);
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
        button* kiad=dynamic_cast<button*>(kiadas);
        button* felt=dynamic_cast<button*>(feltolt);
        button* hozza=dynamic_cast<button*>(hozzaad);
        button* tovabb=dynamic_cast<button*>(atad);
        button* torles=dynamic_cast<button*>(torol);
        button* otorles=dynamic_cast<button*>(otorol);
        Szoveg* szov=dynamic_cast<Szoveg*>(szoveg);
        szamlalo* szamolo=dynamic_cast<szamlalo*>(szam);
        Osszekapcsolo* ossze=dynamic_cast<Osszekapcsolo*>(lis);
        Osszekapcsolo* arazo=dynamic_cast<Osszekapcsolo*>(aras);
        if(ossze&&szamolo&&kiad&&kiad->lenyomvaki()&&ossze->idki()!=-1) {e[ossze->idki()]->ertek-=szamolo->aktualiski();}
        if(szoveg&&szamolo&&hozza&&hozza->lenyomvaki())
        {
            Elem* idg=new Elem(szov->tki(),szamolo->aktualiski());
            e.push_back(idg);
        }
        if(kiad&&felt->lenyomvaki())
        {
            e.erase(e.begin(),e.end());
            for(int i=0;i<5;i++)
            {
                Elem* idg=new Elem(alapanyag[i],10);
                e.push_back(idg);
            }
        }
        if(ossze&&szamolo&&tovabb&&tovabb->lenyomvaki()&&ossze->idki()!=-1)
        {
            Elem* idg=new Elem(e[ossze->idki()]->nev,(e[ossze->idki()]->ertek)*(szamolo->aktualiski()));
            ar.push_back(idg);
        }
        if(arazo&&torles&&arazo->idki()!=-1&&torles->lenyomvaki()) {ar.erase(ar.begin()+arazo->idki());}
        if(arazo&&otorles&&arazo->idki()!=-1&&otorles->lenyomvaki()) {ar.clear();}
        for(int i=0;i<e.size();i++) {if(e[i]->ertek<=0) {e.erase(e.begin()+i);}}
        egyenleg=0;
        for(auto a:ar) {egyenleg+=a->ertek;}
        gout<<move_to(30+gout.twidth("Egyenleg:"),900)<<color(0,0,0)<<box_to(30+gout.twidth("Egyenleg:")+100,950)<<color(255,255,255)<<move_to(30+gout.twidth("Egyenleg:"),900)<<text(to_string(egyenleg));
        gout<<refresh;
    }
}

void Ablak::esemenyKezeles(event ev) {}
