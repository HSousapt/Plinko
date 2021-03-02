#ifndef MAINSTATEMENU_H
#define MAINSTATEMENU_H

#include "State.hpp"

class MainMenuState : public State
{
public:
    MainMenuState(RenderWindow* window);
    virtual ~MainMenuState();

    //Functions
    void update(const float &dt);
    void updateMousePos();
    void render(RenderTarget *target);
    void updateInput(const float &dt);
    void endState();
    void setState();
    void renderText(RenderTarget &target);
    
private:
    Font font;
    Text uiText;
    
    void init_fonts();
    void init_keybinds();
    void init_font();
    void init_text();
};

#endif