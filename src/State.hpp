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

class State
{
public:
    State();
    virtual ~State();

    //Pure virtual functions, child-classes of State inherit these functions and MUST define them
    virtual void update() = 0;
    virtual void render() = 0;

private:

};

#endif