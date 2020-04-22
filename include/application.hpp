#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>
#include <string>

class Widget;

class Application{
    protected:
        std::vector<Widget *> OBJECTS;
        int WIDTH, HEIGHT;
    public:
        Application(int width, int height);
        virtual ~Application(){};
        virtual void Run();
        void RegisterObject(Widget *);
        virtual void Action(std::string param) = 0;
        virtual void ClearScreen();
};

#endif