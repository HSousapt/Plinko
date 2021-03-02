#include "KeyboardController.hpp"

KeyboardController::KeyboardController()
{
    this->init_keys();
}

KeyboardController::~KeyboardController()
{

}

void KeyboardController::setStateKeybinds(string state) 
{
    switch (resolve_state(state))
    {
    case MAINMENU: {
        set_keybind("MOVE_UP", this->supportedKeys.at("Up"));
        set_keybind("MOVE_DOWN", this->supportedKeys.at("Down"));
        set_keybind("SELECT", this->supportedKeys.at("Enter"));
    }
        break;
    case GAMESTATE: {
    }
        break;
    default:
        break;
    }
}

//PRIVATE FUNCTIONS
void KeyboardController::init_keys()
{
    this->supportedKeys["Escape"] = Keyboard::Key::Escape;
    this->supportedKeys["Enter"] = Keyboard::Key::Enter;
    this->supportedKeys["Space"] = Keyboard::Key::Space;
    this->supportedKeys["Left"] = Keyboard::Key::Left;
    this->supportedKeys["Right"] = Keyboard::Key::Right;
    this->supportedKeys["Up"] = Keyboard::Key::Up;
    this->supportedKeys["Down"] = Keyboard::Key::Down;
}

void KeyboardController::set_keybind(string keybind, Keyboard::Key key)
{
    this->keyBinds[keybind] = key;
}


States KeyboardController::resolve_state(string state) 
{
    if(state=="MAIN_MENU")  return States::MAINMENU;
    if(state=="GAME_STATE")  return States::GAMESTATE;
    return States::UNDEFINED;
}