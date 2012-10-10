#include "Game.h"

bool Game::quit = false;
Obj * Game::movement_obj = NULL;
int Game::turn_number = 0;

vector < Menu *> Game::menu_list;
vector < Player *> Game::player_list;
vector < Obj * > Game::turn_order;

void Game::exit()
{
    quit = true;
}

struct SortBySpeed
{
    bool operator() (Obj * x, Obj *y) { return x->get_speed() < y->get_speed();}
};


void Game::update_turn_order()
{
    turn_order.clear();
    for (int i = 0; i < player_list.size(); i++)
    {
        vector < Obj * > temp = player_list[i]->get_team();
        turn_order.insert(turn_order.end(), temp.begin(), temp.end());
    }

    std::sort( turn_order.begin(), turn_order.end(), SortBySpeed());
}


void Game::turn()
{
}
