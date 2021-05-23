#include "keyPad.hpp"

void keyPad::update()
{
    currState = oldState;
    hidGetKeyboardStates(&currState, 1);
}

bool keyPad::keyDown(HidKeyboardKey key)
{
    return hidKeyboardStateGetKey(&currState, key) && !hidKeyboardStateGetKey(&oldState, key);
}