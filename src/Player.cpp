#include "Player.h"

Player::Player(SDL_Color teamColor)
{
    this->panel = new InfoPanel(0, SCREEN_HEIGHT - (SCREEN_HEIGHT*0.25), NULL);
    this->selected_cell = &field[0][0];
    this->teamColor = teamColor;
}

void Player::add_member(Obj * o)
{
    this->team.push_back(o);
}

void Player::remove_member(int pos)
{
    this->team.erase(this->team.begin()+pos);
}

void Player::showPanel()
{
    panel->showPanel();
}

void Player::update_visible()
{
    for (unsigned int i = 0; i < team.size(); i++)
    {
        team[i]->find_visible();
    }
    panel->updateMinMap();
}

void Player::select_cell(int x, int y)
{
    int temp_x = Render::transform(0, SCREEN_WIDTH,  0, VIEW_WIDTH,  x) + h_offset;
    int temp_y = Render::transform(0, SCREEN_HEIGHT*0.75, 0, VIEW_HEIGHT, y) + v_offset;
    this->selected_cell = &field[temp_x][temp_y];
}


void Player::handle_events()
{
    int mouse_x, mouse_y;

    //While there's an event to handle
    while( SDL_PollEvent( &event ) )
    {
        switch (event.type)
        {
            case SDL_QUIT:
                Game::quit = true;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_RIGHT:
                        h_offset += 1;
                        break;

                    case SDLK_LEFT:
                        h_offset -= 1;
                        break;

                    case SDLK_UP:
                        v_offset -= 1;
                        break;

                    case SDLK_DOWN:
                        v_offset += 1;
                        break;

                    case SDLK_ESCAPE:
                        Menu::show_startMenu();
                        break;
                    default:
                        if ( p.get_selected_cell()->get_o() != NULL )
                        {
                            p.get_selected_cell()->get_o()->handleEvents(event);
                        }
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                SDL_WM_GrabInput(SDL_GRAB_ON);
                SDL_GetMouseState(&mouse_x, &mouse_y);

                if (Game::menu_list.size() != 0)
                {
                    Game::menu_list[0]->press(mouse_x, mouse_y);
                }

                else
                {
                    if(mouse_y <= SCREEN_HEIGHT*0.75)
                    {
                        p.select_cell(mouse_x, mouse_y);
                    }
                    else if (mouse_x > SCREEN_WIDTH*0.75)
                    {
                        int temp_x, temp_y;

                        panel->get_minmap()->find_movement(mouse_x, mouse_y, temp_x, temp_y);

                        Render::move_view(temp_x, temp_y);
                    }
                }

                break;

            case SDL_MOUSEBUTTONUP:
                break;

            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&mouse_x, &mouse_y);
                if (mouse_x < (SCREEN_WIDTH * 0.02)) {move_left = true;} else {move_left = false;}
                if (mouse_x > (SCREEN_WIDTH - (SCREEN_WIDTH * 0.02))) {move_right = true;} else {move_right = false;}
                if (mouse_y < (SCREEN_HEIGHT * 0.02)) {move_up = true;} else {move_up = false;}
                if (mouse_y > (SCREEN_HEIGHT - (SCREEN_HEIGHT * 0.02))) {move_down = true;} else {move_down = false;}
                break;
            default:
                break;
        }
    }

    if (move_left) {h_offset -= SCREEN_SPEED * deltaclock;}
    else if (move_right) {h_offset += SCREEN_SPEED * deltaclock;}
    if (move_down) {v_offset += SCREEN_SPEED * deltaclock;}
    else if (move_up) {v_offset -= SCREEN_SPEED * deltaclock;}

    if (h_offset < 0) {h_offset = 0;}
    if (v_offset < 0) {v_offset = 0;}
    if (h_offset + VIEW_WIDTH > FIELD_WIDTH) {h_offset = FIELD_WIDTH - VIEW_WIDTH;}
    if (v_offset + VIEW_HEIGHT > FIELD_HEIGHT) {v_offset = FIELD_HEIGHT - VIEW_HEIGHT;}
}

