#include "Space.h"

Space::Space(){}

SDL_Surface * Space::create_surface()
{
    SDL_Rect background = {0, 0, CELL_SIZE, CELL_SIZE};

    Uint32 rmask, gmask, bmask, amask;
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0x00000000;

    SDL_Surface * temp = SDL_CreateRGBSurface(SDL_SWSURFACE, CELL_SIZE, CELL_SIZE, 32, rmask, gmask, bmask, amask);
    SDL_FillRect(temp, &background, 0x000000);

    return temp;
}

SDL_Surface * Space::s = Space::create_surface();
string Space::title = "Space";
Uint32 Space::mapColor = 0x000000;
