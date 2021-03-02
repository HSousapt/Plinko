#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.hpp"

class GameState : public State
{
public:
    GameState(RenderWindow* window);
    virtual ~GameState();

    //Functions
    void update(const float &dt);
    void render(RenderTarget *target);
    void updateInput(const float &dt);
    void endState();
    void setState();

private:
};

#endif