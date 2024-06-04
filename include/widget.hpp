#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class Widget {
protected:
    int x, y;

public:
    Widget(int x_, int y_);
    virtual void rajzol() = 0;
    virtual bool rajta(int egerx, int egery) = 0;
    virtual void esemenyKezeles(genv::event ev) = 0;
    virtual ~Widget();
};

#endif // WIDGET_HPP
