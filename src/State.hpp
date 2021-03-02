#ifndef STATE_H
#define STATE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <stack>

#include "KeyboardController.hpp"

using namespace sf;
using namespace std;

class State
{
public:
    State(RenderWindow* window);
    virtual ~State();

    //Pure virtual functions, child-classes of State inherit these functions and MUST define them
    virtual void update(const float& dt) = 0;
    virtual void render(RenderTarget *target = nullptr) = 0; //if nothing is given to the function it will render the window
    virtual void updateInput(const float &dt) = 0;
    virtual void endState() = 0;
    virtual void setState() = 0;


    virtual void checkForQuit();
    const bool& getQuitStatus() const;

protected:
    RenderWindow* window;
    KeyboardController KeyControl;
    bool quit;
    string stateName;
        //Mouse position relative to the game window
    Vector2i mousePos;

private:

};

#endif