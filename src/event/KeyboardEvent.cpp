/*
** EPITECH PROJECT, 2019
** KeyboardEvent.cpp
** File description:
** Handle keyboard events
*/

#include <iostream>
#include "../../include/event/KeyboardEvent.hpp"

KeyboardEvent::KeyboardEvent()
{
    initKeyboard();
}

KeyboardEvent::~KeyboardEvent()
{
}

void KeyboardEvent::initKeyboard()
{
    for (irr::u32 i = 0; i < irr::EKEY_CODE::KEY_KEY_CODES_COUNT; i++)
        KeyIsDown[i] = false;
}

bool KeyboardEvent::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
        KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
    }
    return (false);
}

bool KeyboardEvent::IsKeyDown(irr::EKEY_CODE key) const
{
    return (KeyIsDown[key]);
}

void KeyboardEvent::resetKey()
{
    initKeyboard();
}
