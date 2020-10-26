#ifndef BALLS_H
#define BALLS_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

class Balls
{
public:
    Balls();
    ~Balls();

    //Functions
    void update();
    void render(RenderTarget &target);

private:
    Sprite sprite;
    Texture texture;

    //Functions
    void init_texture();

    void init_sprite();
};

#endif