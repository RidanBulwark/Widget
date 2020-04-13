#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"


class Widget{   
protected:
    int X, Y, SIZEX, SIZEY;
public:
    Widget(int x, int y, int sizex, int sizey);
    virtual bool is_selected(int posx, int posy);
    virtual void change(genv::event ev) = 0;
    virtual void draw() = 0;
    virtual std::string give_value() = 0;
};

#endif