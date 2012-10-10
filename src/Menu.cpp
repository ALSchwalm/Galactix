#include "Menu.h"

Menu::Menu(char * title)
{
    this->w = strlen(title) * CELL_SIZE;
    this->title = TTF_RenderText_Blended( font, title, {255, 255, 255} );
    this->x = 30;
    this->y = 30;
}

Menu::Menu(char * title, int x, int y)
{
    this->w = strlen(title) * CELL_SIZE;
    this->title = TTF_RenderText_Blended( font, title, {255, 255, 255} );
    this->x = x;
    this->y = y;
}

void Menu::add_item(char * name, void (*func)())
{
    Button * b = new Button(x+(CELL_SIZE/2), y+(button_list.size() * 30)+(CELL_SIZE*2), name, func);
    this->button_list.push_back(b);
}

void Menu::show_menu()
{
    for (unsigned int i = 0; i < button_list.size(); i++)
    {
        if (button_list[i]->get_width() > w)
        {
            w = button_list[i]->get_width();
        }
    }

    for (unsigned int i = 0; i < button_list.size(); i++) {button_list[i]->update_width(w);}

    SDL_Rect background = {x, y, w+CELL_SIZE, button_list.size()*30 + (CELL_SIZE*2)};
    SDL_FillRect(screen, &background, 0x000000);

    Render::UnfilledRect(screen, x, y, w+CELL_SIZE, button_list.size()*30+(CELL_SIZE*2), 2, 0xffffff);

    Render::apply_surface(x+CELL_SIZE, y, title, screen);


    for (unsigned int i = 0; i < button_list.size(); i++)
    {
        this->button_list[i]->draw_button();
    }


}

void Menu::press(int a, int b)
{
    for (unsigned int i = 0; i < button_list.size(); i++)
    {
        if (button_list[i]->getInRange(a, b))
        {
            button_list[i]->press();
        }
    }
}

void Menu::close()
{
    Game::menu_list.erase(Game::menu_list.begin());
}

void Menu::show_startMenu()
{
    Menu * m = new Menu("Galatrix");
    m->add_item("Start", NULL);
    m->add_item("Save", NULL);
    m->add_item("Load", NULL);
    m->add_item("Exit", Game::exit);
    m->add_item("Close", Menu::close);
    Game::menu_list.push_back(m);
}


