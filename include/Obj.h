#ifndef OBJ_H
#define OBJ_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Global.h"
#include "Cell.h"
#include <vector>
#include <string>

using namespace std;

class Cell;

class Obj
{
    public:
        Obj();

        virtual int get_x() { return x;}
        virtual void set_x(int val) { x = val;}

        virtual int get_y() { return y; }
        virtual void set_y(int val) { y = val;}

        virtual int get_view() {}
        virtual int get_speed() {}

        virtual int get_movement() {}

        virtual char * get_icon() { return icon; }
        virtual string get_title() { return title; }
        virtual SDL_Color get_color() {return teamColor;}

        void find_visible();
        void move();

        virtual void handleEvents(SDL_Event event);
        virtual void draw_ActionSurface();


    protected:
        int x, y;
        SDL_Color teamColor;
        static string title;
        static char * icon;
        static int view;
        static int movement;
};

#endif // OBJ_H
