#ifndef GAMESTATE_H
#define GAMESTATE_H


#include "State.hpp"

class GameState : public State
{
public:
    GameState();
    virtual ~GameState();

    //Functions
    void update();
    void render();

private:
};

#endif