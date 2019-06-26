/*
** EPITECH PROJECT, 2019
** CharacterEvent.hpp
** File description:
** Character event Keyboard
*/

#ifndef CHARACTEREVENT_HPP_
#define CHARACTEREVENT_HPP_

#include <irrlicht.h>

class CharacterEvent {
	public:
		CharacterEvent();
		~CharacterEvent();

        void setForward(irr::EKEY_CODE forward);
        void setBackward(irr::EKEY_CODE backward);
        void setLeft(irr::EKEY_CODE left);
        void setRight(irr::EKEY_CODE right);
        void setPlaceBomb(irr::EKEY_CODE placeBomb);

        irr::EKEY_CODE getForward() const;
        irr::EKEY_CODE getBackward() const;
        irr::EKEY_CODE getLeft() const;
        irr::EKEY_CODE getRight() const;
        irr::EKEY_CODE getPlaceBomb() const;

	private:
        irr::EKEY_CODE _forward;
        irr::EKEY_CODE _backward;
        irr::EKEY_CODE _left;
        irr::EKEY_CODE _right;
        irr::EKEY_CODE _placeBomb;
};

#endif /* !CHARACTEREVENT_HPP_ */
