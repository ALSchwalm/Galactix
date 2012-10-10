#ifndef INFOPANEL_H
#define INFOPANEL_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <sstream>
#include "Space.h"
#include "Render.h"
#include "MinMap.h"

class Obj;
class MinMap;

class InfoPanel
{
    public:
        InfoPanel();
        InfoPanel(int x, int y, Space * s);
        InfoPanel(int x, int y, Space * s, Obj * o);

        int get_x() { return x; }
        void set_x(int val) { x = val; }

        int get_y() { return y; }
        void set_y(int val) { y = val; }

        void showPanel();

        void set_selectedObj(Obj * o) { selectedObj = o; }
        void set_selectedSpace( Space * s ) { selectedSpace = s;}

        MinMap * get_minmap() { return minmap;}
        void updateMinMap();

        void find_movement(int x, int y, int &temp_x, int &temp_y);

    private:
        int x;
        int y;
        Obj * selectedObj;
        Space * selectedSpace;

        MinMap *minmap;
};

#endif // INFOPANEL_H
