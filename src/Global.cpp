#include "Global.h"

Uint32 startclock;
Uint32 currentFPS = 0;
Uint32 deltaclock = 0;

Uint32 waittime = 1000.0f/FPS;
Uint32 framestarttime = 0;
Sint32 delaytime;

bool move_right = false;
bool move_left = false;
bool move_up = false;
bool move_down =false;

int v_offset = 0;
int h_offset = 0;

TTF_Font * font = NULL;

SDL_Surface * screen = NULL;
Cell field[FIELD_WIDTH][FIELD_HEIGHT];

Player p = Player( {0, 0, 255} );
