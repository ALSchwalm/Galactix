#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Fighter.h"
#include "Global.h"
#include "Render.h"
#include "Terrain.h"
#include <time.h>

using namespace std;

bool init()
{

    if ( SDL_Init (SDL_INIT_EVERYTHING) == -1) { return false; }

    screen = SDL_SetVideoMode (SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    if (screen == NULL ) { return false; }

    if( TTF_Init() == -1 ) { return false; }

    font = TTF_OpenFont( "font.ttf", CELL_SIZE);

    if (font == NULL) { return false; }

    SDL_WM_SetCaption("Galatrix v0.0.8", NULL);
    SDL_WM_GrabInput(SDL_GRAB_ON);
    srand ( time(0) );

    Terrain::calculate_terrain();

    Game::player_list.push_back(&p);

    //Make some random ships
    for (int i = 0; i < 20; i++)
    {
        int a = rand() % FIELD_WIDTH;
        int b = rand() % FIELD_HEIGHT;
        Obj * o = new Fighter(a, b, p.get_color());

        if (a < FIELD_WIDTH && b < FIELD_HEIGHT)
            field[a][b].set_o(o);

        p.add_member(o);
    }
    Game::update_turn_order();

    return true;
}

int main( int argc, char* args[])
{
    if (init() == false) { return 1; }

    Menu::show_startMenu();

    p.update_visible();

    //While the user hasn't quits
    while( Game::quit == false )
    {
        //start fps calc
        startclock = SDL_GetTicks();

        Render::draw();

        p.showPanel();
        p.handle_events();

        SDL_Flip( screen );

        //yield back to the cpu
        delaytime = waittime - (SDL_GetTicks() - framestarttime);
        if  (delaytime > 0)
            SDL_Delay((Uint32)delaytime);
        framestarttime = SDL_GetTicks();

        //calculate FPS for movement
        deltaclock = SDL_GetTicks() - startclock;

        if (deltaclock !=  0 )
        {
            currentFPS = 1000/deltaclock;
        }
    }
    SDL_Quit();
    return 0;
}
