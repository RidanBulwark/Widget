#include "graphics.hpp"
#include "List.hpp"

#include <iostream>

using namespace genv;
using namespace std;

List::List(int x, int y, int sizex, int sizey, vector<string> data, int len):
          Widget(x, y, sizex, sizey), DATA(data), FOCUSED(false), 
          SELECTED(0), FIRSTSHOWN(-1), HOVERED(0), LEN(len){}

void List::draw(){
    if(DATA.size()<LEN){
        LEN = DATA.size();
    }

    gout << move_to(X,Y) << color(255, 255, 255) << box(SIZEX, SIZEY)
         << move_to(X+SIZEX-SIZEY, Y) << color(255,166,77) << box(SIZEY, SIZEY) 
         << move_to(X+SIZEX-SIZEY/2-3, Y+gout.cascent()) << color(0,0,0) << text("I");
    if(LEN != 0){
       gout << move_to(X+2,Y+gout.cascent()) << color(0,0,0) << text(DATA[SELECTED]);
    }
    

    if(FOCUSED && LEN != 0){
        for(size_t i = 1;i<=LEN;i++){
            gout << move_to(X,Y+SIZEY*i+i) << color(255, 255, 255) << box(SIZEX, SIZEY)
                 << move_to(X+2, Y+ SIZEY*i + i + gout.cascent()) 
                 << color(0,0,0) << text(DATA[FIRSTSHOWN + i]);
            cout << "FS: " << FIRSTSHOWN 
                 << " i: " << i 
                 << " i + FS: " << i + FIRSTSHOWN 
                 << " HOV: " << HOVERED << '\n';            
            if(i + FIRSTSHOWN == HOVERED){
                gout << move_to(X,Y+SIZEY*i+i) << color(77,255,77) << box(SIZEX, SIZEY)
                     << move_to(X+2, Y+ SIZEY*i + i + gout.cascent()) 
                     << color(0,0,0) << text(DATA[FIRSTSHOWN + i]);
            }
        }
    }
    
}

void List::change(event ev){
    if(FOCUSED && LEN != 0){
        if((ev.type == ev_key && ev.keycode == key_up || 
            ev.type == ev_mouse && ev.button == btn_wheelup)
            && HOVERED > -1){
            HOVERED -= 1;
            if(HOVERED == -1){
                HOVERED = 0;
            }
        }
        if(HOVERED<FIRSTSHOWN + 1 && FIRSTSHOWN > -1){
            FIRSTSHOWN -= 1;
        }

        if((ev.type == ev_key && ev.keycode == key_down || 
            ev.type == ev_mouse && ev.button == btn_wheeldown)
            && HOVERED < DATA.size()){
            HOVERED += 1;
            if(HOVERED>LEN-1 && (FIRSTSHOWN + LEN < DATA.size()-1)){
                FIRSTSHOWN += 1;
            }
            if(HOVERED == DATA.size()){
                HOVERED = DATA.size()-1;
            }
        }
        
        
/*         for(size_t i = 0;i<DATA.size();i++){
            if(X < ev.pos_x && X + SIZEX > ev.pos_x){
                if(Y + SIZEY*i + i  < ev.pos_y && 
                   Y + SIZEY*(i+1) + i > ev.pos_y){
                    HOVERED = i-1;
                }
            }
        } */
        

        if(ev.type == ev_key && ev.keycode == key_enter){
            SELECTED = HOVERED;
            //FOCUSED = false;
        }

        if(ev.type == ev_key && ev.keycode == key_escape){
            FOCUSED = false;
        }
    }
}

bool List::is_selected(int posx, int posy){
    FOCUSED = Widget::is_selected(posx, posy);
    return FOCUSED;
}

string List::give_value(){
    if(LEN != 0){
        return DATA[SELECTED];
    }
    else{
        return "NO DATA";
    }
}

/* vector<string> plus_element(vector<string>& List){
    string a = "";
    cin >> a;
    List.push_back(a);
    return List;
} */