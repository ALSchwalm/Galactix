#ifndef GAME_H
#define GAME_H

#include "Global.h"
#include <algorithm>

class Menu;
class Player;

namespace Game
{
    extern bool quit;
    extern Obj * movement_obj;
    extern vector < Menu *> menu_list;
    extern vector < Player *> player_list;
    extern vector < Obj * > turn_order;
    extern int turn_number;
    void update_turn_order();
    void turn();
    void exit();
};

#endif // GAME_H
