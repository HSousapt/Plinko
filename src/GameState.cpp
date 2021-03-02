#include "GameState.hpp"

GameState::GameState(RenderWindow* window) : State(window)
{
    this->setState();
    this->KeyControl.setStateKeybinds(this->stateName);
}

GameState::~GameState()
{

}

void GameState::update(const float &dt) 
{
    this->updateInput(dt);   
}

void GameState::render(RenderTarget *target) 
{
    
}

void GameState::updateInput(const float &dt) 
{
    this->checkForQuit();
}

void GameState::setState() 
{
    this->stateName = "GAME_STATE";    
}

void GameState::endState() 
{

}
