/*
** EPITECH PROJECT, 2019
** KeyboardEvent.hpp
** File description:
** Handle keyboard events
*/

#ifndef KEYBOARDEVENT_HPP_
#define KEYBOARDEVENT_HPP_

#include <vector>
#include <irrlicht.h>

class KeyboardEvent : public irr::IEventReceiver {
	public:
		KeyboardEvent();
		~KeyboardEvent();
        void initKeyboard();
        bool OnEvent(const irr::SEvent &event);
        bool IsKeyDown(irr::EKEY_CODE key) const;
        void resetKey();

	private:
        bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};

#endif /* !KEYBOARDEVENT_HPP_ */
