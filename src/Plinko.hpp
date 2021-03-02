#ifndef PLINKO_H
#define PLINKO_H

#include "GameState.hpp"
#include "MainMenuState.hpp"
#include "Balls.hpp"

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

/*
*
*   PUBLIC FUNCTIONS
*
*/

    bool isRunning();

    void pollEvents();

    void renderText(RenderTarget &target);

    void updateText();

    void update();

    void render();

    void renderWorld();

    void updateDeltaTime();

    void run();

/*
*
*   Private FUNCTIONS
*
*/

private:
    //Variables
    //Game window
    RenderWindow *window;

    //window VideoMode(for window size, etc...)
    VideoMode vm;

    //Game events
    Event event;

    //Resources
    Font font;

    //Text
    Text uiText;

    //Ball
    Balls *ball;

    //Background Image
    Sprite backgroundS;

    //Background Texture
    Texture backgroundTex;

    //Clock for delta-time
    Clock dtClock;

    //Delta time;
    float dt;

    stack<State*> states;

    //Private functions
    void init_vars();

    void init_window();

    void init_font();

    void init_text();

    void init_ball();

    void init_background();

    void init_states();
};

#endif