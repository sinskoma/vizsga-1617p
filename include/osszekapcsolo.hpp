#ifndef OSSZEKAPCSOLO_HPP
#define OSSZEKAPCSOLO_HPP

#include <vector>
#include "widget.hpp"
#include "graphics.hpp"
#include "lista.hpp"
#include "valasztva.hpp"
#include "ablak.hpp"

class Osszekapcsolo : public Widget {
protected:
    Valasztva valasztva;
    int id;
    std::vector<Ablak::Elem*>& elemek;

public:
    Osszekapcsolo(int x_, int y_, std::vector<Ablak::Elem*>& elemek_);
    void rajzol() override;
    void esemenyKezeles(genv::event ev) override;
    bool rajta(int egerx, int egery) override;
    int idki();
    ~Osszekapcsolo() {}
};

#endif // OSSZEKAPCSOLO_HPP
