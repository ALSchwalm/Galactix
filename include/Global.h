#ifndef GLOBAL_H
#define GLOBAL_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Cell.h"
#include "Player.h"
#include "Menu.h"
#include <vector>
#include <iostream>
#define FPS 100

class Cell;
class Player;
class Menu;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int CELL_SIZE = 12;
const int VIEW_WIDTH =  SCREEN_WIDTH/CELL_SIZE;
const int VIEW_HEIGHT = (SCREEN_HEIGHT/CELL_SIZE) - (SCREEN_HEIGHT/CELL_SIZE)*0.25;
const int FIELD_WIDTH = 500;
const int FIELD_HEIGHT = 500;
const int SCREEN_BPP = 32;

const float SCREEN_SPEED = 0.2;

//FPS vars for testing
extern Uint32 deltaclock;
extern Uint32 currentFPS;
extern Uint32 startclock;

extern Uint32 waittime;
extern Uint32 framestarttime;
extern Sint32 delaytime;

extern bool move_right;
extern bool move_left;
extern bool move_up;
extern bool move_down;

extern int v_offset;
extern int h_offset;

extern SDL_Color textColor;

extern TTF_Font * font;

extern Player p;

extern Cell field[FIELD_WIDTH][FIELD_HEIGHT];

//The surfaces
extern SDL_Surface * screen;

#endif // GLOBAL_H
