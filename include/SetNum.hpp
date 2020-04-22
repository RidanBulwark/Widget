#ifndef SETNUM_HPP_INCLUDED
#define SETNUM_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class SetNum : public Widget{
private:
    int VALUE;
    int CHANGEBOX, MIN, MAX;
    bool FOCUSED;
    Application * PARENT;
public:
    SetNum(Application * parent, int x, int y, int sizex, int sizey, int min, int max);
    virtual void change(genv::event ev);
    virtual void draw();
    virtual bool is_selected(int posx, int posy);
    virtual std::string give_value();
};

#endif