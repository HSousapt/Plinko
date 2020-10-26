#ifndef PLINKO_H
#define PLINKO_H

#include "balls.h"

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

    void updateMousePos();

    void renderText(RenderTarget &target);

    void updateText();

    void update();

    void render();

    //END FUNCTIONS DEFINITION REGION
private:
    //Variables
    //Game window
    RenderWindow *window;

    //window VideoMode(for window size, etc...)
    VideoMode vm;

    //Game events
    Event event;

    //Mouse position relative to the game window
    Vector2i mousePos;

    //Resources
    Font font;

    //Text
    Text uiText;

    //Ball
    Balls *ball;

    //Private functions
    void init_vars();

    void init_window();

    void init_font();

    void init_text();

    void init_ball();
};

#endif