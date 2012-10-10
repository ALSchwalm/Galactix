#ifndef SPACE_H
#define SPACE_H

#include "SDL/SDL.h"
#include "Global.h"
#include <string>

using namespace std;

class Space
{
    public:
        Space();

        virtual SDL_Surface * get_s() {return s;}

        virtual string get_title() { return title; }

        virtual Uint32 get_color() { return mapColor; }

    private:
        static SDL_Surface * create_surface();
        static SDL_Surface * s;
        static Uint32 mapColor;
        static string title;
};

#endif // SPACE_H
