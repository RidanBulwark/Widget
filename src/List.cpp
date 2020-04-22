#include "graphics.hpp"
#include "List.hpp"

#include <iostream>

using namespace genv;
using namespace std;

List::List(Application * parent, int x, int y, int sizex, int sizey, vector<string> data, int len):
          Widget(parent, x, y, sizex, sizey), DATA(data), FOCUSED(false), 
          SELECTED(0), FIRSTSHOWN(0), V_HOVERED(0), DISP_HOVERED(0), LEN(len){}

void List::draw(){
    if(DATA.size()<LEN){
        LEN = DATA.size();
    }
    /* cout << LEN << " " << DATA.size() << '\n'; */
    gout << move_to(X,Y) << color(255, 255, 255) << box(SIZEX, SIZEY)
         << move_to(X+SIZEX-SIZEY, Y) << color(255,166,77) << box(SIZEY, SIZEY) 
         << move_to(X+SIZEX-SIZEY/2-3, Y+SIZEY/2+gout.cascent()/2-2) << color(0,0,0) << text("V");
    if(LEN != 0){
       gout << move_to(X+2,Y+SIZEY/2+gout.cascent()/2-2) << color(0,0,0) << text(DATA[SELECTED]);
    }

    if(FOCUSED && LEN != 0){
        for(size_t i = 0;i<LEN;i++){
            gout << move_to(X,Y+SIZEY*(i+1)+i-1) << color(0,0,0) 
                << line_to(X+SIZEX,Y+SIZEY*(i+1)+i-1);
            gout << move_to(X,Y+SIZEY*(i+1)+i) << color(255, 255, 255) << box(SIZEX, SIZEY)
                << move_to(X+2, Y+ SIZEY*(i+1) + SIZEY/2 + i + gout.cascent()/2-2) 
                << color(0,0,0) << text(DATA[FIRSTSHOWN + i]);
            /* cout << "FS: " << FIRSTSHOWN 
                << " i: " << i 
                << " i + FS: " << i + FIRSTSHOWN 
                << " VHOV: " << V_HOVERED << " DHOV:" << DISP_HOVERED <<
                 " LEN:" << LEN << " DS:" << DATA.size() << '\n'; */            
            if(i + FIRSTSHOWN == DISP_HOVERED){
                gout << move_to(X,Y+SIZEY*(i+1)+i) << color(77,255,77) << box(SIZEX, SIZEY)
                    << move_to(X+2, Y+ SIZEY*(i+1) + SIZEY/2 + i + gout.cascent()/2-2) 
                    << color(0,0,0) << text(DATA[FIRSTSHOWN + i]);
            }
        }
    }
}

void List::change(event ev){
    if(FOCUSED && LEN != 0){
        if((ev.type == ev_key && ev.keycode == key_up || 
            ev.type == ev_mouse && ev.button == btn_wheelup)
            && V_HOVERED > -1){
            V_HOVERED -= 1;
            DISP_HOVERED = V_HOVERED;
            if(V_HOVERED == -1){
                V_HOVERED = 0;
                DISP_HOVERED = V_HOVERED;
            }
        }
        if(V_HOVERED<FIRSTSHOWN && FIRSTSHOWN > 0){
            FIRSTSHOWN -= 1;
        }

        if((ev.type == ev_key && ev.keycode == key_down || 
            ev.type == ev_mouse && ev.button == btn_wheeldown)
            && V_HOVERED < DATA.size()){
            V_HOVERED += 1;
            DISP_HOVERED = V_HOVERED;
            if(V_HOVERED>LEN+FIRSTSHOWN-1 && (FIRSTSHOWN + LEN < DATA.size())){
                FIRSTSHOWN += 1;
            }
            if(V_HOVERED == DATA.size()){
                V_HOVERED = DATA.size()-1;
                DISP_HOVERED = V_HOVERED;
            }
        }
        

        for(size_t i = 0;i<=LEN;i++){
            if(X < ev.pos_x && X + SIZEX > ev.pos_x){
                if(Y + SIZEY*i + i  < ev.pos_y && 
                   Y + SIZEY*(i+1) + i > ev.pos_y){
                    /* cout << "DHOV: " << DISP_HOVERED << " i-1:" << i-1 << '\n'; */
                    DISP_HOVERED = FIRSTSHOWN + i-1;
                    if(DISP_HOVERED < 0){
                        DISP_HOVERED = 0;
                    }
                }
            }
        } 
        
        if(ev.type == ev_key && ev.keycode == key_enter
            || ev.type == ev_mouse && ev.button == btn_right){
            SELECTED = DISP_HOVERED;
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