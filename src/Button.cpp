#include "Button.h"

Button::Button(int x, int y, char * name, void (*func)())
{
    this->name = name;
    this->f = func;
    this->x = x;
    this->y = y;
    this->w = strlen(name) * CELL_SIZE;
    this->h = CELL_SIZE * 2;
}

void Button::draw_button()
{
    Render::UnfilledRect(screen, x, y, w, h, 1, 0xffffff);
    SDL_Surface * s = TTF_RenderText_Blended( font, name, {255, 255, 255} );
    Render::apply_surface(x+CELL_SIZE, y+h/2 - (CELL_SIZE/2), s, screen);
    SDL_FreeSurface(s);
}

void Button::press()
{
    if (f != NULL)
    {
        f();
    }
}

int Button::get_width()
{
    return strlen(name) * CELL_SIZE;
}

bool Button::getInRange(int a, int b)
{
    if ((a >= x && a <= x+w) && (b >= y && b <= y+h))
    {
        return true;
    }
    else
    {
        return false;
    }
}
