#ifndef SHIP_H
#define SHIP_H

#include "Obj.h"
#include "Global.h"
#include "Render.h"

class Fighter: public Obj
{
    public:
        Fighter(int x, int y, SDL_Color textColor);
        void set_health(int val) { health = val; }
        int get_health() { return health; }
        void handleEvents(SDL_Event event);
        void draw_ActionSurface();

        string get_title() { return title; }
        char * get_icon() { return icon; }

        int get_x() { return x;}
        void set_x(int val) { x = val; }

        int get_y() { return y; }
        void set_y(int val) { y = val; }

        int get_view() { return view; }
        int get_speed() { return speed; }

        int get_movement() { return movement; }

        SDL_Color get_color() { return teamColor;}

    private:
        int x, y;
        int health;
        SDL_Color teamColor;
        static int speed;
        static string title;
        static char * icon;
        static int view;
        static int movement;
};

#endif // SHIP_H
