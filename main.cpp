#include "graphics.hpp"
#include "widget.hpp"
#include "SetNum.hpp"
#include "List.hpp"

#include <fstream>
#include <iostream>
#include <vector>
#include <cwchar>

using namespace genv;
using namespace std;

const int width = 400;
const int height = 400;

void ClearScreen(){
    gout << move_to(0,0) << color(0,0,0) << box(width, height);
}

void run(vector<Widget*>& Objects){
    event ev;

    int selected = -1;
    while(gin >> ev){
        if(ev.type == ev_mouse && ev.button == btn_left){
            for(size_t i=0;i<Objects.size();i++){
                if(Objects[i]->is_selected(ev.pos_x, ev.pos_y)){
                    selected = i;
                }
            }
        }
        
        ClearScreen();
        for(Widget* egyik : Objects){
            egyik->draw();
        }
        
        if(selected!=-1){
            Objects[selected]->draw();
            Objects[selected]->change(ev);
        }

        if(ev.type == ev_key && ev.keycode == key_right){
            ofstream Out ("ertekek.txt");
            if(!Out.good()){
                cout << "Fájl nyitás nem jött össze!" << '\n';
            }
            string kifele;
            for(size_t i = 0;i<Objects.size();i++){
                kifele = Objects[i]->give_value();
                Out << kifele << '\n';
            }   
            /* Out << Objects[selected]->give_value() << '\n'; */
            Out.close();
        }
        
        gout << refresh;

    }   
}

int main()
{
    setlocale(LC_ALL, "");
    gout.open(width, height);

    

    vector<Widget*> Objects;
    SetNum * SN1 = new SetNum(10, 10, 100, 20, 0, 100);
    SetNum * SN2 = new SetNum(10, 40, 70, 20, 0, 25);

    vector<string> ListVect1 = {"Egy", "Ketto", "HEHE", "bacsi", "neni", "Jozsi", "Sok"};
    List * L1 = new List(10, 70, 100, 20, ListVect1, 4);

    vector<string> ListVect2 = {"Telapo", "Kacsa", "labda", "konyv", "Terminator"};
    List * L2 = new List(10, 100, 120, 20, ListVect2, 3);

    Objects.push_back(SN1);
    Objects.push_back(SN2);
    Objects.push_back(L1);
    Objects.push_back(L2);

    for(Widget* egyik : Objects){
        egyik->draw();
    }
    gout << refresh;
    run(Objects);

    return 0;
}
