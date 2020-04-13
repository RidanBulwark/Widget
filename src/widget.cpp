#include "widget.hpp"
#include "graphics.hpp"

#include <iostream>

using namespace genv;

Widget::Widget(int x, int y, int sizex, int sizey) : X(x), Y(y), SIZEX(sizex), SIZEY(sizey){}

bool Widget::is_selected(int posx, int posy){
    return X < posx && X+SIZEX > posx && Y < posy && Y+SIZEY > posy;
}
