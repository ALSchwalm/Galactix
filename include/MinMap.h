#ifndef MINMAP_H
#define MINMAP_H

#include "Cell.h"
#include "Global.h"
#include "Render.h"
#include "math.h"

class MinMap
{
    public:
        MinMap();
        MinMap(int x, int y);
        void drawMap();
        void find_movement(int x, int y, int & temp_x, int & temp_y);

        SDL_Surface * get_map() {return map;}
        void set_map(SDL_Surface * val) {map = val;}

        void recalculateMap();

    private:
        int x;
        int y;
        int w;
        int h;

        int box_w;
        int box_h;
        SDL_Surface * create_map();
        float transform(int old_min, int old_max, int new_min, int new_max, float value);

        SDL_Surface * map;
};

#endif // MINMAP_H
