#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

#include <vector>


class List : public Widget{
private:
    std::vector<std::string> DATA;
    bool FOCUSED;
    int SELECTED, FIRSTSHOWN, HOVERED, LEN;
public:
    List(int x, int y, int sizex, int sizey, std::vector<std::string> data, int len);
    virtual void draw();
    virtual void change(genv::event ev);
    virtual bool is_selected(int posx, int posy);
    virtual std::string give_value();
    /* virtual std::vector<std::string> plus_element(); */
};

#endif