#include "application.hpp"
#include "widget.hpp"
#include "graphics.hpp"

#include <iostream>

using namespace genv;

Widget::Widget(Application * parent, int x, int y, int sizex, int sizey) 
              : PARENT(parent), X(x), Y(y), SIZEX(sizex), SIZEY(sizey){
                  PARENT->Application::RegisterObject(this);
              }

bool Widget::is_selected(int posx, int posy){
    return X < posx && X+SIZEX > posx && Y < posy && Y+SIZEY > posy;
}
