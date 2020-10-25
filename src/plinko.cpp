#include "plinko.h"

//Constructor definition
Plinko::Plinko()
{
    this->init_vars();
    this->init_window();
    this->init_font();
    this->init_text();
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

    this->updateMousePos();
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

    this->renderText(*this->window);

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

void Plinko::updateMousePos()
{
    /*
        @return void

        Updates to Mouse Position()
         relative to the window
    */

    this->mousePos = Mouse::getPosition(*this->window);
}

void Plinko::init_font()
{
    /*
        @return void

        Loads a font from a file
    */
    if (!this->font.loadFromFile("fonts/Casino3DLinesMarquee-Italic.ttf"))
    {
        cout << "ERROR :: PLINKO::INIT_FONT -> Failed to load font" << endl;
    }
}

void Plinko::init_text()
{
    /*
        @return void

        Initialize text with a specific font
    */

    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(100);
    this->uiText.setFillColor(Color::Red);
    this->uiText.setString("A Maria e Linda");
}

void Plinko::renderText(RenderTarget &target)
{
    /*

    */
    target.draw(this->uiText);
}

void Plinko::updateText()
{
    /*stringstream ss;

    ss << "Credits: " << this->credits;

    this->uiText.setString(ss.string());*/
}

//END FUNCTIONS DEFINITION REGION