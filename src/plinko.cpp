#include "plinko.h"

//Constructor definition
Plinko::Plinko()
{
    this->init_vars();
    this->init_window();
}

//Destructor definition
Plinko::~Plinko()
{
    delete this->window;
}

//BEGIN FUNCTIONS DEFINITION REGION

const bool Plinko::isRunning()
{
    /*
        @return const bool

        -True if window is open
        -False if window is closed
    */
    return this->window->isOpen();
}

void Plinko::pollEvents()
{
    /*
        @return void

        -polls events
        -checks if window is to be closed
        -checks for keyboard inputs
        -...
    */
    Event event = this->event;
    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            this->window->close();
            break;

        case Event::KeyPressed:
            if (event.key.code == Keyboard::Escape)
            {
                this->window->close();
                break;
            }
        default:
            break;
        }
    }
}

void Plinko::update()
{
    /*
        @return void

        updates the events
    */
    this->pollEvents();

    //Mouse position relative to the window
    cout << "Mouse position: x-> " << Mouse::getPosition(*this->window).x << " y -> " << Mouse::getPosition(*this->window).y << endl;
}

void Plinko::render()
{
    /*
        @return void

        - Clears old Frames
        - Renders objects
        - Display frame in window
    */
    this->window->clear();

    //Draw game objects

    this->window->display();
}

void Plinko::init_vars()
{
    /*
        @return void

        Initialize Game variables
    */
    this->window = nullptr;
}

void Plinko::init_window()
{
    /*
        @return void

        Initialize window
    */
    this->vm.width = 1024;
    this->vm.height = 720;
    this->window = new RenderWindow(this->vm, "Plinko", Style::Titlebar | Style::Close);
}

//END FUNCTIONS DEFINITION REGION