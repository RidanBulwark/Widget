#include "application.hpp"
#include "graphics.hpp"
#include "widget.hpp"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace genv;
using namespace std;

Application::Application(int width, int height):
                        WIDTH(width), HEIGHT(height){}

void Application::ClearScreen(){
    gout << move_to(0,0) << color(220,220,160) << box(WIDTH, HEIGHT);
}

void Application::Run(){
    Application::ClearScreen();
    for(Widget * egy : OBJECTS){
        egy->draw();
    }
    gout << refresh;

    event ev;
    int selected = -1;
    while(gin >> ev){
        if(ev.type == ev_mouse && ev.button == btn_left){
            for(size_t i=0;i<OBJECTS.size();i++){
                if(OBJECTS[i]->is_selected(ev.pos_x, ev.pos_y)){
                    selected = i;
                }
            }
        }
        
        if(selected!=-1){
            OBJECTS[selected]->draw();
            OBJECTS[selected]->change(ev);
        }
        /* cout << " selected:"<<selected << '\n'; */

        if(ev.type == ev_key && ev.keycode == key_right){
            ofstream Out ("ertekek.txt");
            if(!Out.good()){
                cout << "Fájl nyitás nem jött össze!" << '\n';
            }
            string kifele;
            for(size_t i = 0;i<OBJECTS.size();i++){
                kifele = OBJECTS[i]->give_value();
                Out << kifele << '\n';
            }   
            /* Out << OBJECTS[selected]->give_value() << '\n'; */
            Out.close();
        }
        Application::ClearScreen();
    for(Widget * egy : OBJECTS){
        egy->draw();
    }
    gout << refresh;

    }  
}

void Application::RegisterObject(Widget * desc){
    OBJECTS.push_back(desc);
}