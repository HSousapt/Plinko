#include "State.hpp"

State::State(RenderWindow *window)
{
    this->window = window;
}

State::~State()
{
    
}

void State::checkForQuit() 
{
    if(Keyboard::isKeyPressed(Keyboard::Escape))
    {
        this->quit = true;
    }    
}

const bool & State::getQuitStatus() const 
{
    return this->quit;   
}
