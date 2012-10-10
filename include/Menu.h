#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "Global.h"
#include "Game.h"

class Button;

class Menu
{
    public:
        Menu(char * title);
        Menu(char * title, int x, int y);
        void show_menu();
        void add_item(char * name, void (*func)());
        void press(int a, int b);

        int get_width() {return w;}

        static void show_startMenu();
    private:
        static void close();
        SDL_Surface * title;
        vector < Button * > button_list;
        int x, y, w;
};


#endif // MENU_H
