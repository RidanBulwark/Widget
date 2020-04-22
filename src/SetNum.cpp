#include "graphics.hpp"
#include "SetNum.hpp"

#include <iostream>

using namespace genv;
using namespace std;

SetNum::SetNum(Application * parent, int x, int y, int sizex, int sizey, int min, int max):
              Widget(parent,x, y, sizex, sizey),
              MIN(min), MAX(max), VALUE(min), CHANGEBOX(sizey/2), FOCUSED(false){} 

 
void SetNum::draw(){
    gout << move_to(X,Y) << color(77,166,255) << box(SIZEX-CHANGEBOX, SIZEY) 
         << move_to(X+2, Y+2) << color(255, 255, 255) << box(SIZEX-4, SIZEY-4);
    if(abs(VALUE)<10){
    gout << move_to(X + (SIZEX-CHANGEBOX)/2 -4 , Y + SIZEY/2 + gout.cascent()/2 - 2) 
         << color(0,0,0) << text(to_string(VALUE));
    }
    else if(abs(VALUE)<100){
    gout << move_to(X + (SIZEX-CHANGEBOX)/2 -10 , Y + SIZEY/2 + gout.cascent()/2 - 2) 
         << color(0,0,0) << text(to_string(VALUE));
    }
    else if(abs(VALUE)<1000){
    gout << move_to(X + (SIZEX-CHANGEBOX)/2 -16 , Y + SIZEY/2 + gout.cascent()/2 - 2) 
         << color(0,0,0) << text(to_string(VALUE));
    }
    else if(abs(VALUE)<10000){
    gout << move_to(X + (SIZEX-CHANGEBOX)/2 -22 , Y + SIZEY/2 + gout.cascent()/2 - 2) 
         << color(0,0,0) << text(to_string(VALUE));
    }
    else{
    gout << move_to(X +4 , Y + SIZEY/2 + gout.cascent()/2 - 2) 
         << color(0,0,0) << text(to_string(VALUE));
    }
    gout << move_to(X+SIZEX-CHANGEBOX-2, Y) << color(77,166,255) << box(CHANGEBOX,CHANGEBOX-1) 
         << move_to(X+SIZEX-CHANGEBOX+CHANGEBOX/2 -5, Y+CHANGEBOX/2+gout.cascent()/2 - 2) 
         << color(0,0,0) << text("+") 
         << move_to(X+SIZEX-CHANGEBOX-2, Y+CHANGEBOX) << color(77,166,255) << box(CHANGEBOX,CHANGEBOX) 
         << move_to(X+SIZEX-CHANGEBOX+CHANGEBOX/2 -5, Y+CHANGEBOX+CHANGEBOX/2+gout.cascent()/2 - 2) << color(0,0,0) <<  text("-");
}

void SetNum::change(event ev){
    if(FOCUSED){
        if(X+SIZEX-CHANGEBOX < ev.pos_x && X+SIZEX > ev.pos_x && Y < ev.pos_y && Y+CHANGEBOX-1 > ev.pos_y){
            if(ev.type == ev_mouse && ev.button == btn_left && VALUE < MAX){
                VALUE += 1;
                
            }
        }
        if(ev.type == ev_key){
            if(ev.keycode == key_up && VALUE < MAX){
                VALUE += 1;
            }
            if(ev.keycode == key_pgup && VALUE < MAX-9){
                VALUE += 10;
            }
        }   

        if(X+SIZEX-CHANGEBOX < ev.pos_x && X+SIZEX > ev.pos_x && Y+CHANGEBOX < ev.pos_y && Y+CHANGEBOX*2 > ev.pos_y){
            if(ev.type == ev_mouse && ev.button == btn_left && VALUE > MIN){
                VALUE -= 1;
            }
        }
        if(ev.type == ev_key){
            if(ev.keycode == key_down && VALUE > MIN){
                VALUE -= 1;
            }
            if(ev.keycode == key_pgdn && VALUE > MIN+9){
                VALUE -= 10;
            }
        }
    }
}

bool SetNum::is_selected(int posx, int posy){
    FOCUSED = Widget::is_selected(posx, posy);
    return FOCUSED;
}

string SetNum::give_value(){
    return to_string(VALUE);
}