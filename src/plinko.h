#ifndef PLINKO_H
#define PLINKO_H
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;
using namespace sf;

/*

    GAME "ENGINE" CLASS

*/

class Plinko
{
public:
    //Constructor
    Plinko();
    //Destructor
    ~Plinko();

    //BEGIN FUNCTIONS DEFINITION REGION

    const bool isRunning();

    void pollEvents();

    void update();

    void render();

    //END FUNCTIONS DEFINITION REGION
private:
    //Game window
    RenderWindow *window;

    //window VideoMode(for window size, etc...)
    VideoMode vm;

    //Game events
    Event event;

    void init_vars();

    void init_window();
};

#endif