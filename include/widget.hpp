#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "application.hpp"

class Widget{   
protected:
    int X, Y, SIZEX, SIZEY;
    Application * PARENT;
public:
    Widget(Application * parent, int x, int y, int sizex, int sizey);
    virtual bool is_selected(int posx, int posy);
    virtual void change(genv::event ev) = 0;
    virtual void draw() = 0;
    virtual std::string give_value() = 0;
};

#endif