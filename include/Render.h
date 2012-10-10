#ifndef RENDER_H
#define RENDER_H

#include "SDL/SDL.h"
#include "Global.h"

class Obj;

namespace Render
{
    void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination );

    void UnfilledRect(SDL_Surface * screen, int x, int y, int w, int h, int b, Uint32 color);
    void draw();
    void draw_movement(Obj * o);
    void move_view(int x, int y);
    SDL_Surface * get_blank(int width, int height, int alpha);
    float transform(int old_min, int old_max, int new_min, int new_max, float value);

    void draw_grid();
}

#endif // RENDER_H
