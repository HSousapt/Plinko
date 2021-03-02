#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include <SFML/Window.hpp>
#include <map> 

using namespace std;
using namespace sf;

enum States{
    MAINMENU,
    GAMESTATE,
    UNDEFINED,
};

class KeyboardController
{
public:
    KeyboardController();
    virtual ~KeyboardController();

    map<string, Keyboard::Key> keyBinds;
    map<string, Keyboard::Key> supportedKeys;

    void setStateKeybinds(string);

private:
    States resolve_state(string);
    void init_keys();
    void set_keybind(string, Keyboard::Key);
};

#endif