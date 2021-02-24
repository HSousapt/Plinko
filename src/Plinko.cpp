#include "Plinko.hpp"

//Constructor definition
Plinko::Plinko()
{
    this->init_vars();
    this->init_window();
    this->init_background();
    this->init_font();
    this->init_text();
    this->init_ball();
}

//Destructor definition
Plinko::~Plinko()
{
    delete this->window;
    delete this->ball;
}

//BEGIN FUNCTIONS DEFINITION REGION

bool Plinko::isRunning()
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

    //Render background
    this->renderWorld();

    //Draw game objects

    //this->renderText(*this->window);

    this->ball->render(*this->window);
    this->window->display();
}

void Plinko::run() 
{
    //Event polling
    while (this->isRunning())
    {

        //Update and store Delta-time
        this->updateDeltaTime();
        
        //BEGIN UPDATE REGION
        {
            this->update();
        }
        //END UPDATE REGIN

        //BEGIN RENDER REGION
        {
            this->render();
        }
        //END RENDER REGION
    }    
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
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
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

void Plinko::init_background()
{
    if(!this->backgroundTex.loadFromFile("../textures/3.png"))
    {
        cout << "ERROR: PLINKO::INIT_BACKGROUND -> Failed to load texture!" << endl;
    }

    //scaling the sprite to the size of the window
    Vector2u textureSize = this->backgroundTex.getSize();
    Vector2u windowSize = this->window->getSize();


    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y;

    this->backgroundS.setTexture(this->backgroundTex);

    this->backgroundS.setScale(scaleX, scaleY);
}

void Plinko::init_font()
{
    /*
        @return void

        Loads a font from a file
    */
    if (!this->font.loadFromFile("../fonts/Casino3DLinesMarquee-Italic.ttf"))
    {
        cout << "ERROR :: PLINKO::INIT_FONT -> Failed to load font!" << endl;
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
    this->uiText.setString("PLINKO");
}

void Plinko::renderText(RenderTarget &target)
{
    /*
        @return void

        draws the text on the &target
    */
    target.draw(this->uiText);
}

void Plinko::renderWorld()
{
    this->window->draw(this->backgroundS);
}

void Plinko::updateDeltaTime() 
{
    /*
        @return void

        Resets delta-time variable with the time it takes to update and render one frame
    */    

   this->dt = this->dtClock.restart().asSeconds();
}

void Plinko::updateText()
{
    /*stringstream ss;

    ss << "Credits: " << this->credits;

    this->uiText.setString(ss.string());*/
}

void Plinko::init_ball()
{
    this->ball = new Balls();
}

//END FUNCTIONS DEFINITION REGION