/*
** EPITECH PROJECT, 2019
** MainMenu.hpp
** File description:
** Main menu header
*/

#ifndef MAINMENU_HPP_
#define MAINMENU_HPP_

#define NB_BUTTONS (5)

#include <string>
#include <vector>
#include <map>
#include <irrlicht.h>
#include "../../sound/Music.hpp"
#include "../../Core.hpp"

class MainMenu {
	public:
		MainMenu(Core *core);
		~MainMenu();
        MenuController runMenu();
		MenuController buttonsHandler();
        void createButtons();
        void destroyButtons();
        void getCoreVariableValues(Core *core);
        void loadImages();

	private:
        std::vector<irr::video::ITexture *> _menuImages;
        std::vector<irr::gui::IGUIButton *> _menuButtons;
        irr::video::IVideoDriver *_driver;
        irr::IrrlichtDevice *_device;
        irr::scene::ISceneManager *_sceneManager;
        irr::gui::IGUIEnvironment *_gui;
        int _width;
        int _height;
};

#endif /* !MAINMENU_HPP_ */
