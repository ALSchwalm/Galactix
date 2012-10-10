#ifndef CELL_H
#define CELL_H

#include "SDL/SDL.h"
#include "Obj.h"
#include "Space.h"

class Obj;
class Space;

class Cell
{
    public:
        Cell();
        Cell(int x, int y, Obj * o);
        Cell(int x, int y, Space * sp);
        Cell(int x, int y, Obj * o, Space * sp);

        int get_x() { return x; }
        void set_x(int val) { x = val; }

        int get_y() { return y; }
        void set_y(int val) { y = val; }

        void set_visible(bool val) { visible = val; }
        bool get_visible() { return visible; }

        Obj * get_o() { return o;}
        void set_o(Obj * val) {o = val;}
        Space * get_sp() {return sp;}
        void set_sp(Space * val) {sp = val;}

        SDL_Surface * get_surface();

    private:

        int x, y;
        bool visible;
        Obj * o;
        Space * sp;

};

#endif // CELL_H
