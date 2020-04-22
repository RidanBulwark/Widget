#include "graphics.hpp"
#include "application.hpp"
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

class MyApp : public Application{
    protected:
        SetNum *SN1, *SN2;
        List *L1, *L2;
    public:
        MyApp(int width, int height):Application(width, height){
            SN1 = new SetNum(this, 10, 10, 100, 20, 0, 100);
            SN2 = new SetNum(this, 10, 40, 70, 40, 0, 25);
            
            vector<string> ListVect1 = {"Egy", "Ketto", "HEHE", "bacsi", "neni", "Jozsi", "Sok"};
            L1 = new List(this, 10, 160, 100, 20, ListVect1, 4);

            vector<string> ListVect2 = {/*"Telapo"  , "Kacsa", "labda", "konyv", "Terminator" */};
            L2 = new List(this, 10, 100, 120, 40, ListVect2, 3);
        }

        void Action(string param){
            cout << "";
        }
};


int main()
{
    setlocale(LC_ALL, "");
    gout.open(width, height);
    /* gout << move_to(0,0) << color(220,220,160) << box(width, height); */
    MyApp First(width, height);
    First.Run();
    return 0;
}
