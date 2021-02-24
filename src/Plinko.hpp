#ifndef PLINKO_H
#define PLINKO_H

#include "State.hpp"
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

    //BEGIN FUNCTIONS DEFINITION REGION

    bool isRunning();

    void pollEvents();

    void updateMousePos();

    void renderText(RenderTarget &target);

    void updateText();

    void update();

    void render();

    void renderWorld();

    void updateDeltaTime();

    void run();

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
};

#endif