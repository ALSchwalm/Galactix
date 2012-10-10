#include "Render.h"

void Render::draw_grid()
{
    Uint32 color = 0x00111111;
    SDL_Rect line;
    for (int i = 0; i < VIEW_WIDTH; i++)
    {
        line = {i * CELL_SIZE + (h_offset - (int)h_offset), 0, 1, VIEW_HEIGHT*CELL_SIZE};
        SDL_FillRect(screen, &line, color);
    }

    for (int i = 0; i < VIEW_HEIGHT; i++)
    {
        line = {0, i *CELL_SIZE, VIEW_WIDTH*CELL_SIZE + (v_offset - (int)v_offset), 1};
        SDL_FillRect(screen, &line, color);
    }
}

void Render::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

void Render::UnfilledRect(SDL_Surface * screen, int x, int y, int w, int h, int b, Uint32 color)
{
    SDL_Rect line = {x, y, w, b};
    SDL_FillRect(screen, &line, color);

    line = {x, y, b, h};
    SDL_FillRect(screen, &line, color);

    line = {x, y+(h-b), w, b};
    SDL_FillRect(screen, &line, color);

    line = {x+(w-b), y, b, h};
    SDL_FillRect(screen, &line, color);
}

float Render::transform(int old_min, int old_max, int new_min, int new_max, float value)
{
	float oldRange = old_max - old_min;
	float newRange = new_max - new_min;
	float newValue = (((value - old_min) * newRange)/oldRange) + new_min;
	return newValue;
}

//this can be optimized
void Render::draw_movement(Obj * o)
{
    for (int k = -(o->get_movement()); k <= o->get_movement(); k++)
    {
        for (int l = -(o->get_movement()); l <= o->get_movement(); l++)
        {
            if (abs(k) + abs(l) <= o->get_movement())
            {
                if (o->get_x()+k <= FIELD_WIDTH &&
                o->get_y()+l < FIELD_HEIGHT &&
                o->get_x()+k >= 0 &&
                o->get_y()+l >= 0)
                {
                    SDL_Surface * s = Render::get_blank(CELL_SIZE, CELL_SIZE, 50);
                    SDL_Rect background = {0, 0, CELL_SIZE, CELL_SIZE};
                    SDL_FillRect(s, &background, 0x00ff00);
                    Render::apply_surface((o->get_x()+k - h_offset) * CELL_SIZE , (o->get_y()+l- v_offset)*CELL_SIZE, s, screen);
                    SDL_FreeSurface(s);
                }
            }
        }
    }
}

void Render::draw()
{
    SDL_Rect background = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_FillRect(screen, &background, 0x00333333);

    for (int i = h_offset; i < VIEW_WIDTH+h_offset; i++)
    {
        for (int j = v_offset; j< VIEW_HEIGHT+v_offset; j++)
        {
            int x = field[i][j].get_x();
            int y = field[i][j].get_y();
            SDL_Surface * cell_surface = field[i][j].get_surface();

            if (field[i][j].get_visible() == true)
            {
                Render::apply_surface((x - h_offset) * CELL_SIZE,
                              (y - v_offset) * CELL_SIZE,
                               cell_surface,
                               screen);
                if (field[i][j].get_o() != NULL)
                {
                    SDL_free(cell_surface);
                }
            }
        }
    }

    draw_grid();

    if (p.get_selected_cell() != NULL)
    {
        Render::UnfilledRect(screen, p.get_selected_cell()->get_x()*CELL_SIZE - (h_offset*CELL_SIZE),
                             p.get_selected_cell()->get_y()*CELL_SIZE - (v_offset*CELL_SIZE),
                             CELL_SIZE,
                             CELL_SIZE,
                             1,
                             0x00ff00 );
    }

    if (Game::movement_obj != NULL)
    {
        draw_movement(Game::movement_obj);
    }


    for (int i = (Game::menu_list.size()-1); i >= 0; i--)
    {
        Game::menu_list[i]->show_menu();
    }
}

SDL_Surface * Render::get_blank(int width, int height, int alpha)
{
    Uint32 rmask, gmask, bmask, amask;
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x00000000;

    SDL_Surface * blank = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, rmask, gmask, bmask, amask);
    SDL_SetAlpha (blank, SDL_SRCALPHA, alpha);
    return blank;
}
void Render::move_view(int x, int y)
{
    h_offset = x - (VIEW_WIDTH / 2);
    v_offset = y - (VIEW_HEIGHT / 2);
}
