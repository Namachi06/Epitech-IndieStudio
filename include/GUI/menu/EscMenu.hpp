/*
** EPITECH PROJECT, 2019
** EscMenu.hpp
** File description:
** Pause menu
*/

#ifndef ESCMENU_HPP_
#define ESCMENU_HPP_

#define NB_ESC_BUTTONS (2)

#include <vector>
#include <map>
#include <functional>
#include <irrlicht.h>
#include "../../sound/Music.hpp"
#include "../../event/KeyboardEvent.hpp"

enum EscMenuController
{
    ESC_CONTINUE,
    ESC_QUIT,
    ESC_RESTART,
    ESC_NONE
};

class EscMenu {
    public:
        EscMenu(irr::IrrlichtDevice *device, KeyboardEvent &key, int width, int height);
        ~EscMenu();
        EscMenuController runEscMenu();
        EscMenuController escButtonsHandler();
        void loadImages();
        void loadSounds();
        void createButtons();
        void destroyEscMenuButtons();

    private:
        std::vector<irr::video::ITexture *> _escMenuImages;
        std::vector<irr::gui::IGUIButton *> _escButtons;
        irr::IrrlichtDevice *_device;
        irr::video::IVideoDriver *_driver;
        irr::gui::IGUIEnvironment *_gui;
        std::map<std::string, std::unique_ptr<Music>> _sounds;
        KeyboardEvent &_key;
        int _width;
        int _height;
};

#endif /* !ESCMENU_HPP_ */
