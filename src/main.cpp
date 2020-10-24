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
            if (event.type == Event::Closed)
                window.close();
        }
        //BEGIN UPDATE REGION
        //END RENDER REGIN

        //BEGIN RENDER REGION
        {
            window.clear();
            window.draw(shape);
            window.display();
        }
        //END RENDER REGION
    }

    return 0;
}