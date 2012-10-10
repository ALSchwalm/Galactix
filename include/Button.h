#ifndef BUTTON_H
#define BUTTON_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Render.h"
#include "string"


class Button
{
    public:
        Button(int x, int y, char * name, void (*func)());
        void draw_button();
        void press();
        int get_width();
        bool getInRange(int a, int b);
        void update_width(int val){w = val;}
    private:
        void (*f)();
        char * name;
        int x, y, w, h;
};

#endif // BUTTON_H
