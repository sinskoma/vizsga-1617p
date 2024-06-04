#include "menu.hpp"

using namespace std;
using namespace genv;

Menu::Menu(int XX_, int YY_):Ablak(XX_,YY_)
{
    indit=false;
    mezo = new szamlalo(XX/4, 300, XX/2, 100, 15, 30);
    v.push_back(mezo);
    Widget* iksz = new Menugomb(XX/2-300,600,0);
    v.push_back(iksz);
    Widget* kor = new Menugomb(XX/2+100,600,1);
    v.push_back(kor);
    Widget* sz = new Szoveg(100,100,"teszt");
    v.push_back(sz);
}
Menu::~Menu() {for (auto a : v) {delete a;} delete mezo;}

void Menu::rajzol()
{
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<font("LiberationSans-Regular.ttf",50)<<color(255,255,255)<<move_to(XX/2-450,200)<<text("Valaszd ki kerlek a kivant mezok szamat!")<<
    move_to(XX/2-425,450)<<text("Kattinst a valasztani kivant karakterre!");
};

void Menu::esemenyKezeles(event ev)
{
    while (gin >> ev&&!indit)
    {
        for(auto a:v)
        {
            a->esemenyKezeles(ev);
            if(ev.keycode==key_escape) {exit(0);}
            if(Menugomb* menugomb = dynamic_cast<Menugomb*>(a)) {if ((menugomb->tipuski() == 0 || menugomb->tipuski() == 1)&&menugomb->kijelolveki()==true) {indit=true;}}
            gout << refresh;
        }
    }
}

int Menu::aktualiski()
{
    szamlalo* atad=dynamic_cast<szamlalo*>(mezo);
    return atad->aktualiski();
}

int Menu::karakterki()
{
    for(auto a:v)
    {
        if(Menugomb* menugomb = dynamic_cast<Menugomb*>(a))
        {
            if(menugomb->tipuski()==0&&menugomb->kijelolveki()==true) {return 1;}
            else if(menugomb->tipuski()==1&&menugomb->kijelolveki()==true) {return 2;}
        }
    }
}
