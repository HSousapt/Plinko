#include "balls.h"

Balls::Balls()
{
    this->init_sprite();
    this->init_texture();
}

Balls::~Balls()
{
}

void Balls::update()
{
}

void Balls::render(RenderTarget &target)
{
    target.draw(this->sprite);
}

void Balls::init_texture()
{
    /*
        @return void

        Loads texture from file
    */

    if (!this->texture.loadFromFile("textures/ok.png"))
    {
        cout << "ERROR :: BALLS::INIT_TEXTURE -> Failed to load texture!" << endl;
    }
}

void Balls::init_sprite()
{
    /*
        @return void

        Sets a texture to a Sprite
    */

    this->sprite.setTexture(this->texture);
}