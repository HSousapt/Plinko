#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char **argv)
{
    //Window creation
    RenderWindow window(VideoMode(1024, 768), "SFML works!");

    //Shape Creation
    CircleShape shape(100.f);
    shape.setFillColor(Color::Green);

    //Event polling
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                    window.close();
                break;
            }
        }
        //BEGIN UPDATE REGION
        //END UPDATE REGIN

        //BEGIN RENDER REGION
        {
            /* Clear old frame */
            window.clear();

            /* Draw the Game */
            window.draw(shape);

            /* Window is done drawing */
            window.display();
        }
        //END RENDER REGION
    }

    return 0;
}