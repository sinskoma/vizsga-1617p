#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP
#include "palya.hpp"
#include "menu.hpp"

class JatekMester
{
    protected:
        int aktualisjatekos;
    public:
        JatekMester(int be);
        void valtas(int& soros);
        bool nyertes(std::vector<Widget*> m, int db);
        bool betelt(std::vector<Widget*> m, int db);
        virtual ~JatekMester();
};

#endif // JATEKMESTER_HPP
