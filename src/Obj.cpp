#include "Obj.h"

Obj::Obj(){this->teamColor = {255, 255, 255};}

void Obj::find_visible()
{
    for (int k = -(this->get_view()); k <= this->get_view(); k++)
    {
        for (int l = -(this->get_view()); l <= this->get_view(); l++)
        {
            if (abs(k) + abs(l) <= this->get_view())
            {
                if (this->get_x()+k <= FIELD_WIDTH &&
                this->get_y()+l < FIELD_HEIGHT &&
                this->get_x()+k >= 0 &&
                this->get_y()+l >= 0)
                {
                    field[this->get_x()+k][this->get_y()+l].set_visible(true);
                }
            }
        }
    }
}

void Obj::handleEvents(SDL_Event event){Game::quit = true;}
void Obj::draw_ActionSurface(){}
string Obj::title;
char * Obj::icon;
int Obj::view;
int Obj::movement;
