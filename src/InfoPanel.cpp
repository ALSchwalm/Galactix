#include "InfoPanel.h"

stringstream s;

InfoPanel::InfoPanel(){}

InfoPanel::InfoPanel(int x, int y, Space * s)
{
    this->x = x;
    this->y = y;
    this->selectedSpace = s;

    this->minmap = new MinMap(x + (SCREEN_WIDTH * 0.75), y);
}

InfoPanel::InfoPanel(int x, int y, Space * s, Obj * o)
{
    this->x = x;
    this->y = y;
    this->selectedSpace = s;
    this->selectedObj = o;
}

void InfoPanel::updateMinMap()
{
    this->minmap->recalculateMap();
}


void InfoPanel::showPanel()
{
    SDL_Rect background = {x, y, SCREEN_WIDTH, SCREEN_HEIGHT*0.25};
    SDL_FillRect(screen, &background, 0x000000);

    Render::UnfilledRect(screen, x, y, SCREEN_WIDTH, SCREEN_HEIGHT*0.25, 5, 0xffffff);


    s << h_offset << ", " << v_offset << ", " << currentFPS;
    SDL_Surface * t = TTF_RenderText_Blended( font, s.str().c_str(), {255, 255, 255} );
    Render::apply_surface(x+CELL_SIZE, y+CELL_SIZE, t, screen);
    s.str("");
    s.clear();

    if (p.get_selected_cell()->get_o() != NULL && p.get_selected_cell()->get_visible() == true)
    {
        t = TTF_RenderText_Blended( font, p.get_selected_cell()->get_o()->get_title().c_str(), {255, 255, 255});
        Render::apply_surface(x+CELL_SIZE, y+2*CELL_SIZE, t, screen);

        p.get_selected_cell()->get_o()->draw_ActionSurface();
    }
    else if (p.get_selected_cell()->get_visible() == false)
    {
        t = TTF_RenderText_Blended( font, "This cell is obscured by the fog of war", {255, 255, 255});
        Render::apply_surface(x+CELL_SIZE, y+2*CELL_SIZE, t, screen);
    }

    Render::UnfilledRect(screen, x+SCREEN_WIDTH*0.25, y, SCREEN_WIDTH*0.50, SCREEN_HEIGHT*0.25, 2, 0xffffff);

    SDL_FreeSurface(t);
    minmap->drawMap();
}
