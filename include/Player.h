#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"

#include "InfoPanel.h"
#include <vector>

using namespace std;

class Obj;
class InfoPanel;
class Cell;

class Player
{
    public:
        Player(SDL_Color teamColor);
        void handle_events();

        vector < Obj * > get_team() { return team; }
        void set_team(vector < Obj * > val) { team = val; }

        SDL_Color get_color(){ return teamColor; }

        void add_member(Obj * o);
        void remove_member(int pos);
        void update_visible();
        void select_cell(int x, int y);
        void showPanel();

        Cell * get_selected_cell() {return selected_cell;}

    private:
        SDL_Event event;

        vector < Obj * > team;
        Cell * selected_cell;
        InfoPanel * panel;

        SDL_Color teamColor;
};

#endif // PLAYER_H
