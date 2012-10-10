#include "Fighter.h"

//using namespace std;
int Fighter::speed = 20;
string Fighter::title = "Fighter";
char * Fighter::icon = "o";
int Fighter::view = 8;
int Fighter::movement = 25;

Fighter::Fighter(int x, int y, SDL_Color teamColor)
{
    this->x = x;
    this->y = y;
    this->view = 15;
    this->health = 100;
    this->teamColor = teamColor;
}

void Fighter::handleEvents(SDL_Event event)
{
    switch (event.type)
    {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
                case SDLK_a:
                    if (Game::movement_obj == NULL)
                        Game::movement_obj = this;
                    else if (Game::movement_obj != this)
                        Game::movement_obj = this;
                    else
                        Game::movement_obj = NULL;
                    break;
                default:
                    break;
            }
    }
}

void Fighter::draw_ActionSurface()
{
    Render::apply_surface(SCREEN_WIDTH*0.25 + CELL_SIZE, SCREEN_HEIGHT*0.75 + CELL_SIZE, TTF_RenderText_Shaded( font, "a: move" , {255, 255, 255}, {0,0,0} ), screen);
}
