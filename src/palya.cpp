#include "palya.hpp"
#include "mezo.hpp"
#include "JatekMester.hpp"

using namespace genv;

Palya::Palya(int XX_, int YY_, int darab, int soros_) : Ablak(XX_, YY_), db(darab), soros(soros_)
{
    meret=299;
    for(int o=0;o<db;o++)
    {
        for(int s=0;s<db;s++)
        {
            Widget* widget=new Mezo(o,s,YY/db,0);
            m.push_back(widget);
        }
    }
}

Palya::~Palya() {}

void Palya::rajzol()
{
    gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY);
    gout<<move_to(1200,300)<<color(255,255,255)<<font("LiberationSans-Regular.ttf",50)<<text("Az aktualis jatekos:");
    for(auto a:m) {a->rajzol();}
    canvas c(300,300);
    if(soros==1)
    {
        for(int i=0;i<10;i++)
        {
            c<<move_to(0,i)<<color(255,0,0)<<line_to(meret-i,meret)<<move_to(i,0)<<line_to(meret,meret-i)
            <<move_to(meret-i,0)<<line_to(0,meret-i)<<move_to(meret,i)<<line_to(i,meret);
        }
    }
    else if(soros==2)
    {
        for (int i=0;i<=300;i++)
        {
            for (int j=0;j<=300;j++)
            {
                if (abs((i-150)*(i-150)+(j-150)*(j-150)-145*145)<=15*100)
                {
                    c<<move_to(i,j) <<color(101,147,245)<<dot;
                }
            }
        }
    }
    gout<<stamp(c,1250,450);
    gout<<refresh;
}

void Palya::esemenyKezeles(event ev)
{
    while(gin>>ev && ev.keycode != key_escape)
    {
        for(auto a:m)
        {
            bool valtott=false;
            Mezo* mezo=dynamic_cast<Mezo*>(a);
            if(mezo->tipuski()==0) {valtott=true;}
            a->esemenyKezeles(ev);
            if(mezo!=nullptr) {mezo->tipusbe(soros);}
            if(mezo->tipuski()==0) {valtott=false;}
            if(ev.button==btn_left&&valtott) {jatek->valtas(soros); rajzol();}
        }
        if(jatek->nyertes(m,db)) {jatek->valtas(soros); rajzol();break;}
        else if(jatek->betelt(m,db))
        {
            while(gin>>ev&&ev.keycode!=key_enter)
            {
                gout<<move_to(0,0)<<color(0,0,0)<<box(XX,YY)<<font("LiberationSans-Regular.ttf",50)<<move_to(XX/2-gout.twidth("A palya betelt. Nyomj Esc-et a kilepeshez.")/2,YY/2)<<color(255,255,255)<<text("A palya betelt. Nyomj Esc-et a kilepeshez.")<<refresh;
                if(ev.keycode==key_escape) {exit(0);}
            }
        }
        gout << refresh;
    }
    if(ev.keycode==key_escape) {exit(0);}
}
