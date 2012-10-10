#include "MinMap.h"

MinMap::MinMap(){}

MinMap::MinMap(int x, int y)
{
    this->x = x;
    this->y = y;
    this->w = SCREEN_WIDTH * 0.25;
    this->h = SCREEN_HEIGHT * 0.25;
    this->box_w = Render::transform(0, FIELD_WIDTH, 0, w, VIEW_WIDTH);
    this->box_h = Render::transform(0, FIELD_HEIGHT, 0, w, VIEW_HEIGHT);
    this->map = NULL;
}

void MinMap::find_movement(int x, int y, int & temp_x, int & temp_y)
{
    x -= (SCREEN_WIDTH  * 0.75);
    y -= (SCREEN_HEIGHT * 0.75);

    temp_x = Render::transform(0, w, 0, FIELD_WIDTH, x);
    temp_y = Render::transform(0, h, 0, FIELD_HEIGHT, y);
}

void MinMap::recalculateMap()
{
    this->map = create_map();
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;

    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp)
    {
        case 1:
            *p = pixel;
            break;

        case 2:
            *(Uint16 *)p = pixel;
            break;

        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            }
            else
            {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}

SDL_Surface * MinMap::create_map()
{
    SDL_Surface * temp_map = Render::get_blank(this->w, this->h, 255);
    SDL_LockSurface(temp_map);

    int t_x, t_y;

    for (int i=0;i<FIELD_WIDTH;i++) {
        for (int j=0;j<FIELD_HEIGHT;j++) {

            t_x = Render::transform(0, FIELD_WIDTH, 0, this->w, i);
            t_y = Render::transform(0, FIELD_HEIGHT, 0, this->h, j);

            if (field[i][j].get_visible() == true)
            {
                putpixel(temp_map, t_x, t_y, field[i][j].get_sp()->get_color());
            }
            else
            {
                putpixel(temp_map, t_x , t_y, 0x33333333);
            }
        }
    }
    SDL_UnlockSurface(temp_map);
    return temp_map;
}

void MinMap::drawMap()
{
    int local_x, local_y;

    Render::apply_surface(this->x, this->y, this->map, screen);

    SDL_Rect block;
    Render::UnfilledRect(screen, x, y, w, h, 1, 0xffffff);

    for (unsigned int i = 0; i < p.get_team().size(); i++)
    {
        Obj * o = p.get_team()[i];

        local_x = Render::transform(0, FIELD_WIDTH, 0, w, o->get_x());
        local_y = Render::transform(0, FIELD_HEIGHT, 0, h, o->get_y());

        block = {x + local_x, y + local_y, 2, 2};
        SDL_FillRect(screen, &block, SDL_MapRGB(screen->format, o->get_color().r, o->get_color().g, o->get_color().b));
    }

    local_x = Render::transform(0, FIELD_WIDTH, 0, w, p.get_selected_cell()->get_x());
    local_y = Render::transform(0, FIELD_HEIGHT, 0, h, p.get_selected_cell()->get_y());

    block  = {x + local_x, y + local_y, 2, 2};
    SDL_FillRect(screen, &block, 0x00ff00);

    local_x = Render::transform(0, FIELD_WIDTH-VIEW_WIDTH, 0, w - box_w, h_offset);
    local_y = Render::transform(0, FIELD_HEIGHT-VIEW_HEIGHT, 0, h - box_h, v_offset);

    Render::UnfilledRect(screen, x+ local_x, y+ local_y, box_w, box_h, 1, 0xffffff);



}
