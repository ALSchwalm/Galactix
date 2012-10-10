#include "Cell.h"
#include "SDL/SDL.h"

Cell::Cell() {}

Cell::Cell(int x, int y, Obj * o)
{
    this->x = x;
    this->y = y;
    this->o = o;
    this->sp = NULL;
    this->visible = false;
}

Cell::Cell(int x, int y, Obj * o, Space * sp)
{
    this->x = x;
    this->y = y;
    this->o = o;
    this->sp = sp;
    this->visible = false;
}

Cell::Cell(int x, int y, Space * sp)
{
    this->x = x;
    this->y = y;
    this->sp = sp;
    this->o = NULL;
    this->visible = false;
}

SDL_Surface * Cell::get_surface()
{
    if (this->o == NULL)
    {
        return this->sp->get_s();
    }
    else
    {
        SDL_Surface * temp = SDL_ConvertSurface(this->sp->get_s(), this->sp->get_s()->format, this->sp->get_s()->flags);
        Render::apply_surface(2,-2,TTF_RenderText_Blended( font, this->o->get_icon(), this->o->get_color()), temp);
        return temp;
    }
}
