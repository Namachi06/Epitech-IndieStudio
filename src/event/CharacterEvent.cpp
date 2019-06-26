/*
** EPITECH PROJECT, 2019
** CharacterEvent.cpp
** File description:
** Character keyboard event
*/

#include "../../include/event/CharacterEvent.hpp"

CharacterEvent::CharacterEvent()
{
}

CharacterEvent::~CharacterEvent()
{
}

void CharacterEvent::setForward(irr::EKEY_CODE forward)
{
    _forward = forward;
}

void CharacterEvent::setBackward(irr::EKEY_CODE backward)
{
    _backward = backward;
}

void CharacterEvent::setLeft(irr::EKEY_CODE left)
{
    _left = left;
}

void CharacterEvent::setRight(irr::EKEY_CODE right)
{
    _right = right;
}

void CharacterEvent::setPlaceBomb(irr::EKEY_CODE placeBomb)
{
    _placeBomb = placeBomb;
}

irr::EKEY_CODE CharacterEvent::getForward() const
{
    return (_forward);
}

irr::EKEY_CODE CharacterEvent::getBackward() const
{
    return (_backward);
}

irr::EKEY_CODE CharacterEvent::getLeft() const
{
    return (_left);
}

irr::EKEY_CODE CharacterEvent::getRight() const
{
    return (_right);
}

irr::EKEY_CODE CharacterEvent::getPlaceBomb() const
{
    return (_placeBomb);
}
