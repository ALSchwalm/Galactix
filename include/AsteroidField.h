#ifndef ASTEROIDFIELD_H
#define ASTEROIDFIELD_H

#include "Space.h"

class AsteroidField: public Space
{
    public:
        AsteroidField ();
        SDL_Surface * get_s() {return s;}

        string get_title() { return title; }

        Uint32 get_color() { return mapColor; }

    private:
        static SDL_Surface * create_surface();
        static SDL_Surface * s;
        static string title;
        static Uint32 mapColor;
};

#endif // ASTEROIDFIELD _H
