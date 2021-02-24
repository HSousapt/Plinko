#include "Balls.hpp"

Balls::Balls()
{
    this->init_texture();
    this->init_sprite();
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

    if (!this->texture.loadFromFile("../textures/pokerchip1.png"))
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