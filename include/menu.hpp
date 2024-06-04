#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "graphics.hpp"
#include "szamlalo.hpp"
#include "widget.hpp"
#include "menugomb.hpp"
#include "ablak.hpp"
#include "palya.hpp"
#include "szoveg.hpp"
#include <vector>

class Menu:public Ablak
{
private:
    std::vector<Widget*> v; bool indit; Widget* mezo;
public:
    Menu(int XX_, int YY_);
    ~Menu();
    void rajzol();
    void esemenyKezeles(genv::event ev);
    int aktualiski();
    int karakterki();
};

#endif // MENU_HPP_INCLUDED
