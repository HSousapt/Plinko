#include "MainMenuState.hpp"


//Constructor
MainMenuState::MainMenuState(RenderWindow *window) : State(window)
{
    this->setState();
    this->init_fonts();
    this->init_text();
}

//Destructor
MainMenuState::~MainMenuState()
{

}


/*
*
*   PUBLIC FUNCTIONS
*
*/

void MainMenuState::update(const float &dt) 
{
    this->updateInput(dt);    
    this->updateMousePos();
}

void MainMenuState::updateMousePos()
{
    /*    @return void

        Updates to Mouse Position()
         relative to the window
    */
    this->mousePos = Mouse::getPosition(*this->window);
}

void MainMenuState::render(RenderTarget *target) 
{
    if(!target)
    {
        target = this->window;
    }

    renderText(*this->window);
}

void MainMenuState::renderText(RenderTarget &target)
{
    /*
        @return void

        draws the text on the &target
    */
    target.draw(this->uiText);
}

void MainMenuState::updateInput(const float &dt) 
{
        this->checkForQuit();
}

void MainMenuState::endState() 
{
    
}

void MainMenuState::setState() 
{
    this->stateName = "MAIN_MENU";    
}

/*
*
*   PRIVATE FUNCTIONS
*
*/

void MainMenuState::init_fonts() 
{
    /*
        @return void

        Loads a font from a file
    */
    if (!this->font.loadFromFile("../fonts/Casino3DLinesMarquee.ttf"))
    {
        cout << "ERROR :: PLINKO::INIT_FONT -> Failed to load font!" << endl;
    }
}

void MainMenuState::init_keybinds() 
{
    this->KeyControl.setStateKeybinds(this->stateName);
}

void MainMenuState::init_text()
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
