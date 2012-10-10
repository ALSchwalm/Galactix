#include "AsteroidField.h"

AsteroidField::AsteroidField (){}

SDL_Surface * AsteroidField::create_surface()
{

    SDL_Rect background = {0, 0, CELL_SIZE, CELL_SIZE};

    SDL_Surface * temp = Render::get_blank(CELL_SIZE, CELL_SIZE, 255);
    SDL_FillRect(temp, &background, 0xff00ffff);

    return temp;
}

SDL_Surface * AsteroidField::s = create_surface();
string AsteroidField::title = "AsteroidField";
Uint32 AsteroidField::mapColor = 0xff00ffff;
