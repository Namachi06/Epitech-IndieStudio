/*
** EPITECH PROJECT, 2019
** EscMenu.cpp
** File description:
** Pause menu
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "../../../include/GUI/menu/EscMenu.hpp"

EscMenu::EscMenu(irr::IrrlichtDevice *device, KeyboardEvent &key, int width, int height) :
    _device(device), _key(key), _width(width), _height(height)
{
    _driver = _device->getVideoDriver();
    _gui = _device->getGUIEnvironment();
    loadImages();
    loadSounds();
    std::cout << "EscMenu Ready" << std::endl;
}

EscMenu::~EscMenu()
{
    if (!_escButtons.empty())
        destroyEscMenuButtons();
    if (!_escMenuImages.empty())
        _escMenuImages.clear();
}

EscMenuController EscMenu::runEscMenu()
{
    EscMenuController escController = ESC_NONE;

    createButtons();
    _device->getCursorControl()->setVisible(true);
    _key.resetKey();
    _sounds["openMenu"]->play();
     while (_device->run() && escController == EscMenuController::ESC_NONE && !_key.IsKeyDown(irr::KEY_ESCAPE)) {
        _driver->beginScene(true, true, irr::video::SColor(0, 0, 0, 0));
        _driver->draw2DImage(_escMenuImages[0],
            irr::core::rect<irr::s32>(0, 0, _width, _height),
            irr::core::rect<irr::s32>(0, 0, _width, _height));
        _gui->drawAll();
        escController = escButtonsHandler();
        _driver->endScene();
    }
    _sounds["closeMenu"]->play();
    _device->getCursorControl()->setVisible(false);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return (escController);
}

EscMenuController EscMenu::escButtonsHandler()
{
    std::vector<irr::gui::IGUIButton *>::iterator it = _escButtons.begin();

    for (int i = 0; it != _escButtons.end(); it++, i++) {
        if ((*it)->isPressed()) {
            (*it)->setPressed(false);
            return ((EscMenuController)i);
        }
    }
    return (EscMenuController::ESC_NONE);
}

void EscMenu::loadImages()
{
    _escMenuImages.push_back(_driver->getTexture("./assets/images/menu_backg.jpg"));
    _escMenuImages.push_back(_driver->getTexture("./assets/images/CONTINUE.png"));
    _escMenuImages.push_back(_driver->getTexture("./assets/images/EXIT.png"));
}

void EscMenu::loadSounds()
{
    _sounds.emplace("openMenu", std::unique_ptr<Music>(new Music("./assets/sounds/openMenu.wav")));
    _sounds.emplace("closeMenu", std::unique_ptr<Music>(new Music("./assets/sounds/closeMenu.wav")));
    _sounds["openMenu"]->setVolume(100);
    _sounds["closeMenu"]->setVolume(100);
}

void EscMenu::createButtons()
{
    int i = 0;
    int y = _height / 2.8;
    int x = _width / 1.3;

    while (i < NB_ESC_BUTTONS) {
        y += _height / 9.7;
        _escButtons.push_back(_gui->addButton(irr::core::rect<irr::s32>
            (x - _width / 2, y - _height / 15.5, _width / 2, y)));
        _escButtons[i]->setImage(_escMenuImages[i + 1]);
        _escButtons[i]->setScaleImage();
        _escButtons[i]->setIsPushButton();
        i++;
    }
}

void EscMenu::destroyEscMenuButtons()
{
    std::vector<irr::gui::IGUIButton *>::iterator it = _escButtons.begin();

    for (; it != _escButtons.end(); it++)
        (*it)->remove();
    _escButtons.clear();
}
